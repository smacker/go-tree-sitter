package sitter

import (
	"bytes"
	"context"
	"runtime"
	"strconv"
	"strings"
	"sync"
	"testing"
	"time"

	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
)

func TestRootNode(t *testing.T) {
	assert := assert.New(t)

	n, err := ParseCtx(context.Background(), []byte("1 + 2"), getTestGrammar())
	assert.NoError(err)

	assert.Equal(uint32(0), n.StartByte())
	assert.Equal(uint32(5), n.EndByte())
	assert.Equal(Point{
		Row:    0,
		Column: 0,
	}, n.StartPoint())
	assert.Equal(Point{
		Row:    0,
		Column: 5,
	}, n.EndPoint())
	assert.Equal("(expression (sum left: (expression (number)) right: (expression (number))))", n.String())
	assert.Equal("expression", n.Type())
	assert.Equal(Symbol(7), n.Symbol())

	assert.Equal(false, n.IsNull())
	assert.Equal(true, n.IsNamed())
	assert.Equal(false, n.IsMissing())
	assert.Equal(false, n.IsExtra())
	assert.Equal(false, n.IsError())
	assert.Equal(false, n.HasChanges())
	assert.Equal(false, n.HasError())

	assert.Equal(uint32(1), n.ChildCount())
	assert.Equal(uint32(1), n.NamedChildCount())

	assert.Nil(n.Parent())
	assert.Nil(n.NextSibling())
	assert.Nil(n.NextNamedSibling())
	assert.Nil(n.PrevSibling())
	assert.Nil(n.PrevNamedSibling())

	assert.NotNil(n.Child(0))
	assert.NotNil(n.NamedChild(0))
	assert.Nil(n.ChildByFieldName("unknown"))

	assert.NotNil(n.NamedChild(0).ChildByFieldName("left"))
}

func TestTree(t *testing.T) {
	assert := assert.New(t)

	parser := NewParser()

	parser.Debug()
	parser.SetLanguage(getTestGrammar())
	tree, err := parser.ParseCtx(context.Background(), nil, []byte("1 + 2"))
	assert.NoError(err)
	n := tree.RootNode()

	assert.Equal(uint32(0), n.StartByte())
	assert.Equal(uint32(5), n.EndByte())
	assert.Equal("expression", n.Type())
	assert.Equal("(expression (sum left: (expression (number)) right: (expression (number))))", n.String())

	sum := n.Child(0)
	assert.Equal("(expression (number))", sum.Child(0).String())
	assert.Equal("left", sum.FieldNameForChild(0))
	assert.Equal("(expression (number))", sum.Child(2).String())
	assert.Equal("right", sum.FieldNameForChild(2))
	assert.Equal("", sum.FieldNameForChild(100)) // out of range

	// change 2 -> (3 + 3)
	newText := []byte("1 + (3 + 3)")
	tree.Edit(EditInput{
		StartIndex:  4,
		OldEndIndex: 5,
		NewEndIndex: 11,
		StartPoint: Point{
			Row:    0,
			Column: 4,
		},
		OldEndPoint: Point{
			Row:    0,
			Column: 5,
		},
		NewEndPoint: Point{
			Row:    0,
			Column: 11,
		},
	})
	// check that it changed tree
	assert.True(n.HasChanges())
	assert.True(n.Child(0).HasChanges())
	assert.False(n.Child(0).Child(0).HasChanges()) // left side of the sum didn't change
	assert.True(n.Child(0).Child(2).HasChanges())

	tree2, err := parser.ParseCtx(context.Background(), tree, newText)
	assert.NoError(err)
	n = tree2.RootNode()
	assert.Equal("(expression (sum left: (expression (number)) right: (expression (expression (sum left: (expression (number)) right: (expression (number)))))))",
		n.String())

	descendantNode := n.NamedDescendantForPointRange(Point{Row: 0, Column: 5}, Point{Row: 0, Column: 11})
	assert.NotNil(descendantNode, "Descendant node was nil")
	assert.Equal("(3 + 3)", descendantNode.Content(newText))
}

func TestErrorNodes(t *testing.T) {
	assert := assert.New(t)

	parser := NewParser()

	parser.Debug()
	parser.SetLanguage(getTestGrammar())
	tree, err := parser.ParseCtx(context.Background(), nil, []byte("1 + a"))
	assert.NoError(err)
	n := tree.RootNode()

	assert.True(n.HasError())
	assert.Equal("(expression (number) (ERROR (UNEXPECTED '\\0')))", n.String())

	number := n.Child(0)
	assert.False(number.HasError())
	assert.False(number.IsError())
	error_node := n.Child(1)
	assert.True(error_node.HasError())
	assert.True(error_node.IsError())

	tree, err = parser.ParseCtx(context.Background(), nil, []byte("1 +"))
	assert.NoError(err)
	n = tree.RootNode()

	assert.True(n.HasError())
	assert.Equal("(expression (sum left: (expression (number)) right: (expression (MISSING number))))", n.String())

	sum := n.Child(0)
	assert.True(sum.HasError())
	left := sum.Child(0)
	assert.False(left.HasError())
	right := sum.Child(2)
	assert.True(right.HasError())
	assert.False(right.IsError())
	missing := right.Child(0)
	assert.True(missing.HasError())
	assert.False(missing.IsError())
	assert.True(missing.IsMissing())
}

func TestLanguage(t *testing.T) {
	assert := assert.New(t)
	js := getTestGrammar()

	assert.Equal(uint32(9), js.SymbolCount())
	assert.Equal(js.SymbolName(3), "+")
	assert.Equal(js.SymbolType(3), SymbolTypeAnonymous)
	assert.Equal(js.SymbolName(4), "number")
	assert.Equal(js.SymbolType(4), SymbolTypeRegular)

	assert.Equal(SymbolTypeRegular.String(), "Regular")
}

func TestGC(t *testing.T) {
	assert := assert.New(t)

	parser := NewParser()

	parser.SetLanguage(getTestGrammar())
	tree, err := parser.ParseCtx(context.Background(), nil, []byte("1 + 2"))
	assert.NoError(err)
	n := tree.RootNode()

	r := isNamedWithGC(n)
	assert.True(r)
}

func isNamedWithGC(n *Node) bool {
	runtime.GC()
	time.Sleep(500 * time.Microsecond)
	return n.IsNamed()
}

func TestSetOperationLimit(t *testing.T) {
	assert := assert.New(t)

	parser := NewParser()
	assert.Equal(0, parser.OperationLimit())

	parser.SetOperationLimit(10)
	assert.Equal(10, parser.OperationLimit())
}

func TestOperationLimitParsing(t *testing.T) {
	assert := assert.New(t)

	parser := NewParser()
	parser.SetOperationLimit(10)
	parser.SetLanguage(getTestGrammar())
	items := []string{}
	for i := 0; i < 100; i++ {
		items = append(items, strconv.Itoa(i))
	}
	code := strings.Join(items, " + ")
	tree, err := parser.ParseCtx(context.Background(), nil, []byte(code))
	assert.EqualError(err, ErrOperationLimit.Error())
	assert.Nil(tree)
}

func TestContextCancellationParsing(t *testing.T) {
	assert := assert.New(t)
	ctx, cancel := context.WithCancel(context.Background())
	defer cancel()

	parser := NewParser()
	parser.SetLanguage(getTestGrammar())
	items := []string{}
	// the content needs to be big so that we have enough time to cancel
	for i := 0; i < 10000; i++ {
		items = append(items, strconv.Itoa(i))
	}
	code := strings.Join(items, " + ")

	started := make(chan bool)
	done := make(chan bool)

	var tree *Tree
	var err error
	go func() {
		defer close(started)
		defer close(done)
		start := time.Now()
		started <- true
		tree, err = parser.ParseCtx(ctx, nil, []byte(code))
		t.Logf("parsing complete after %s, error: %+v\n", time.Since(start), err)
		done <- true
	}()

	<-started
	cancel()
	<-done

	assert.EqualError(err, context.Canceled.Error())
	assert.Nil(tree)

	// make sure we can re-use parse after cancellation
	ctx = context.Background()
	tree, err = parser.ParseCtx(ctx, nil, []byte("1 + 1"))
	assert.NotNil(tree)
	assert.NoError(err)
}

func TestIncludedRanges(t *testing.T) {
	assert := assert.New(t)

	// sum code with sum code in a comment
	code := "1 + 2\n//3 + 5"

	parser := NewParser()
	parser.SetLanguage(getTestGrammar())
	mainTree, err := parser.ParseCtx(context.Background(), nil, []byte(code))
	assert.NoError(err)
	assert.Equal(
		"(expression (sum left: (expression (number)) right: (expression (number))) (comment))",
		mainTree.RootNode().String(),
	)
	commentNode := mainTree.RootNode().NamedChild(1)
	assert.Equal("comment", commentNode.Type())

	commentRange := Range{
		StartPoint: Point{
			Row:    commentNode.StartPoint().Row,
			Column: commentNode.StartPoint().Column + 2,
		},
		EndPoint:  commentNode.EndPoint(),
		StartByte: commentNode.StartByte() + 2,
		EndByte:   commentNode.EndByte(),
	}

	parser.SetIncludedRanges([]Range{commentRange})
	commentTree, err := parser.ParseCtx(context.Background(), nil, []byte(code))

	assert.NoError(err)
	assert.Equal(
		"(expression (sum left: (expression (number)) right: (expression (number))))",
		commentTree.RootNode().String(),
	)
}

func TestSameNode(t *testing.T) {
	assert := assert.New(t)

	parser := NewParser()
	parser.SetLanguage(getTestGrammar())
	tree, err := parser.ParseCtx(context.Background(), nil, []byte("1 + 2"))
	assert.NoError(err)

	n1 := tree.RootNode()
	n2 := tree.RootNode()

	assert.True(n1 == n2)

	n1 = tree.RootNode().NamedChild(0)
	n2 = tree.RootNode().NamedChild(0)

	assert.True(n1 == n2)
}

func TestQuery(t *testing.T) {
	js := "1 + 2"

	// test single capture
	testCaptures(t, js, "(sum left: (expression) @left)", []string{
		"1",
	})

	// test multiple captures
	testCaptures(t, js, "(sum left: _* @left right: _* @right)", []string{
		"1",
		"2",
	})

	// test match only
	parser := NewParser()
	parser.SetLanguage(getTestGrammar())
	tree, err := parser.ParseCtx(context.Background(), nil, []byte(js))
	assert.NoError(t, err)
	root := tree.RootNode()

	q, err := NewQuery([]byte("(sum) (number)"), getTestGrammar())
	assert.Nil(t, err)

	qc := NewQueryCursor()
	qc.Exec(q, root)

	var matched int
	for {
		_, ok := qc.NextMatch()
		if !ok {
			break
		}

		matched++
	}

	assert.Equal(t, 3, matched)
}

func testCaptures(t *testing.T, body, sq string, expected []string) {
	assert := assert.New(t)

	parser := NewParser()
	parser.SetLanguage(getTestGrammar())
	tree, err := parser.ParseCtx(context.Background(), nil, []byte(body))
	assert.NoError(err)
	root := tree.RootNode()

	q, err := NewQuery([]byte(sq), getTestGrammar())
	assert.Nil(err)

	qc := NewQueryCursor()
	qc.Exec(q, root)

	actual := []string{}
	for {
		m, ok := qc.NextMatch()
		if !ok {
			break
		}

		for _, c := range m.Captures {
			actual = append(actual, c.Node.Content([]byte(body)))
		}
	}

	assert.EqualValues(expected, actual)
}

func TestQueryError(t *testing.T) {
	assert := assert.New(t)

	q, err := NewQuery([]byte("((unknown) name: (identifier))"), getTestGrammar())

	assert.Nil(q)
	assert.NotNil(err)
	assert.EqualValues(&QueryError{Offset: 0x02, Type: QueryErrorNodeType,
		Message: "invalid node type 'unknown' at line 1 column 0"}, err)
}

func doWorkLifetime(t testing.TB, n *Node) {
	for i := 0; i < 100; i++ {
		// this will trigger an actual bug (if it still there)
		s := n.String()
		require.Equal(t, "(expression (sum left: (expression (number)) right: (expression (number))))", s)
	}
}

func TestParserLifetime(t *testing.T) {
	var wg sync.WaitGroup
	for i := 0; i < 10; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			for i := 0; i < 10; i++ {
				p := NewParser()
				p.SetLanguage(getTestGrammar())
				data := []byte("1 + 2")
				// create some memory/CPU pressure
				data = append(data, bytes.Repeat([]byte(" "), 1024*1024)...)

				tree, err := p.ParseCtx(context.Background(), nil, data)
				assert.NoError(t, err)
				root := tree.RootNode()
				// make sure we have no references to the Parser
				p = nil
				// must be a separate function, and it shouldn't accept the parser, only the Tree
				doWorkLifetime(t, root)
			}
		}()
	}
	wg.Wait()
}

func TestTreeCursor(t *testing.T) {
	assert := assert.New(t)

	input := []byte(`1 + 2`)

	root, err := ParseCtx(context.Background(), input, getTestGrammar())
	assert.NoError(err)
	c := NewTreeCursor(root)

	assert.True(c.CurrentNode() == root)
	assert.Equal("", c.CurrentFieldName())

	assert.False(c.GoToParent())
	assert.False(c.GoToNextSibling())
	assert.Equal(int64(-1), c.GoToFirstChildForByte(100))

	assert.True(c.GoToFirstChild())
	assert.Equal("sum", c.CurrentNode().Type())
	assert.True(c.GoToFirstChild())
	assert.Equal("expression", c.CurrentNode().Type())
	assert.Equal("left", c.CurrentFieldName())
	assert.True(c.GoToNextSibling())
	assert.Equal("+", c.CurrentNode().Type())
	assert.False(c.GoToFirstChild())
	assert.True(c.GoToNextSibling())
	assert.Equal("expression", c.CurrentNode().Type())
	assert.True(c.GoToFirstChild())
	assert.Equal("number", c.CurrentNode().Type())

	assert.True(c.GoToParent())
	assert.True(c.GoToParent())
	assert.Equal("sum", c.CurrentNode().Type())
	nodeForReset := c.CurrentNode()

	assert.Equal(int64(2), c.GoToFirstChildForByte(4))
	assert.Equal("expression", c.CurrentNode().Type())

	c.Reset(nodeForReset)
	assert.Equal("sum", c.CurrentNode().Type())
	assert.False(c.GoToParent())
}

func TestLeakParse(t *testing.T) {
	ctx := context.Background()
	parser := NewParser()
	parser.SetLanguage(getTestGrammar())

	for i := 0; i < 100000; i++ {
		_, _ = parser.ParseCtx(ctx, nil, []byte("1 + 2"))
	}

	runtime.GC()

	var m runtime.MemStats
	runtime.ReadMemStats(&m)

	// shouldn't exceed 1mb that go runtime takes
	assert.Less(t, m.Alloc, uint64(1024*1024))
}

func TestLeakRootNode(t *testing.T) {
	ctx := context.Background()
	parser := NewParser()
	parser.SetLanguage(getTestGrammar())

	for i := 0; i < 100000; i++ {
		tree, err := parser.ParseCtx(ctx, nil, []byte("1 + 2"))
		assert.NoError(t, err)
		_ = tree.RootNode()
	}

	runtime.GC()

	var m runtime.MemStats
	runtime.ReadMemStats(&m)

	// shouldn't exceed 1mb go runtime takes
	assert.Less(t, m.Alloc, uint64(1024*1024))
}

func TestParseInput(t *testing.T) {
	assert := assert.New(t)

	parser := NewParser()
	parser.SetLanguage(getTestGrammar())

	// empty input
	input := Input{
		Encoding: InputEncodingUTF8,
		Read: func(offset uint32, position Point) []byte {
			return nil
		},
	}
	tree, err := parser.ParseInputCtx(context.Background(), nil, input)
	assert.NoError(err)
	n := tree.RootNode()
	assert.Equal("(ERROR)", n.String())

	// return all data in one go
	var readTimes int
	inputData := []byte("12345 + 23456")

	input.Read = func(offset uint32, position Point) []byte {
		if readTimes > 0 {
			return nil
		}
		readTimes++

		return inputData
	}
	tree, err = parser.ParseInputCtx(context.Background(), nil, input)
	assert.NoError(err)
	n = tree.RootNode()
	assert.Equal("(expression (sum left: (expression (number)) right: (expression (number))))", n.String())
	assert.Equal(readTimes, 1)

	// return all data in multiple sequantial reads
	input.Read = func(offset uint32, position Point) []byte {
		if int(offset) >= len(inputData) {
			return nil
		}
		readTimes++
		end := int(offset + 5)
		if len(inputData) < end {
			end = len(inputData)
		}

		return inputData[offset:end]
	}
	tree, err = parser.ParseInputCtx(context.Background(), nil, input)
	assert.NoError(err)
	n = tree.RootNode()
	assert.Equal("(expression (sum left: (expression (number)) right: (expression (number))))", n.String())
	assert.Equal(readTimes, 4)
}

func TestLeakParseInput(t *testing.T) {
	ctx := context.Background()
	parser := NewParser()
	parser.SetLanguage(getTestGrammar())

	inputData := []byte("1 + 2")
	input := Input{
		Encoding: InputEncodingUTF8,
		Read: func(offset uint32, position Point) []byte {
			if offset > 0 {
				return nil
			}

			return inputData
		},
	}

	for i := 0; i < 100000; i++ {
		_, _ = parser.ParseInputCtx(ctx, nil, input)
	}

	runtime.GC()

	var m runtime.MemStats
	runtime.ReadMemStats(&m)

	// shouldn't exceed 1mb that go runtime takes
	assert.Less(t, m.Alloc, uint64(1024*1024))
}

// see https://github.com/smacker/go-tree-sitter/issues/75
func TestCursorKeepsQuery(t *testing.T) {
	source := bytes.Repeat([]byte("1 + 1"), 10000)

	parser := NewParser()
	parser.SetLanguage(getTestGrammar())

	tree := parser.Parse(nil, source)
	root := tree.RootNode()

	for i := 0; i < 100; i++ {
		query, _ := NewQuery(
			[]byte("(number) @match"),
			getTestGrammar(),
		)

		qc := NewQueryCursor()

		qc.Exec(query, root)

		for {
			// ensure qc.NextMatch() doesn't  cause a segfault
			match, exists := qc.NextMatch()
			if !exists || match == nil {
				break
			}
		}
	}
}

func BenchmarkParse(b *testing.B) {
	ctx := context.Background()
	parser := NewParser()
	parser.SetLanguage(getTestGrammar())
	inputData := []byte("1 + 2")

	b.ResetTimer()

	for i := 0; i < b.N; i++ {
		_, _ = parser.ParseCtx(ctx, nil, inputData)
	}
}

func BenchmarkParseCancellable(b *testing.B) {
	ctx := context.Background()
	ctx, cancel := context.WithCancel(ctx)
	defer cancel()

	parser := NewParser()
	parser.SetLanguage(getTestGrammar())
	inputData := []byte("1 + 2")

	b.ResetTimer()

	for i := 0; i < b.N; i++ {
		_, _ = parser.ParseCtx(ctx, nil, inputData)
	}
}

func BenchmarkParseInput(b *testing.B) {
	ctx := context.Background()
	parser := NewParser()
	parser.SetLanguage(getTestGrammar())

	inputData := []byte("1 + 2")
	input := Input{
		Encoding: InputEncodingUTF8,
		Read: func(offset uint32, position Point) []byte {
			if offset > 0 {
				return nil
			}

			return inputData
		},
	}

	b.ResetTimer()

	for i := 0; i < b.N; i++ {
		_, _ = parser.ParseInputCtx(ctx, nil, input)
	}
}
