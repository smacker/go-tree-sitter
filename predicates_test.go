package sitter

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestQueryWithPredicates(t *testing.T) {
	testCases := []struct {
		success bool
		msg     string
		pattern string
	}{
		{
			success: false,
			msg:     "#match?: too few arguments",
			pattern: `((expression) @capture
 (#match? "this"))`,
		},
		{
			success: false,
			msg:     "#match?: too many arguments",
			pattern: `((expression) @capture
 (#match? a b "this"))`,
		},
		{
			success: false,
			msg:     "#match?: need a capture as first argument",
			pattern: `((expression) @capture
 (#match? "a" "this"))`,
		},
		{
			success: false,
			msg:     "#match?: need a string as second argument",
			pattern: `((expression) @capture
 (#match? @capture @capture))`,
		},
		{
			success: true,
			msg:     "#match?: success test",
			pattern: `((expression) @capture
 (#match? @capture "^[A-Z]"))`,
		},
		{
			success: false,
			msg:     "#not-match?: too few arguments",
			pattern: `((expression) @capture
 (#not-match? "this"))`,
		},
		{
			success: false,
			msg:     "#not-match?: too many arguments",
			pattern: `((expression) @capture
 (#not-match? a b "this"))`,
		},
		{
			success: false,
			msg:     "#not-match?: need a capture as first argument",
			pattern: `((expression) @capture
 (#not-match? "a" "this"))`,
		},
		{
			success: false,
			msg:     "#not-match?: need a string as second argument",
			pattern: `((expression) @capture
 (#not-match? @capture @capture))`,
		},
		{
			success: true,
			msg:     "#not-match?: success test",
			pattern: `((expression) @capture
 (#not-match? @capture "^[A-Z]"))`,
		},
		{
			success: false,
			msg:     "#eq?: too few arguments",
			pattern: `((expression) @capture
 (#eq? "this"))`,
		},
		{
			success: false,
			msg:     "#eq?: too many arguments",
			pattern: `((expression) @capture
 (#eq? a b "this"))`,
		},
		{
			success: false,
			msg:     "#eq?: need a capture as first argument",
			pattern: `((expression) @capture
 (#eq? "a" "this"))`,
		},
		{
			success: true,
			msg:     "#eq?: success test",
			pattern: `((expression) @capture
 (#eq? @capture "this"))`,
		},
		{
			success: true,
			msg:     "#eq?: success double predicate test",
			pattern: `((expression) @capture
 (#eq? @capture @capture) (#eq? @capture "this"))`,
		},
		{
			success: true,
			msg:     "#eq?: success test",
			pattern: `((expression) @capture
 (#eq? @capture @capture))`,
		},
		{
			success: false,
			msg:     "#not-eq?: too few arguments",
			pattern: `((expression) @capture
 (#not-eq? "this"))`,
		},
		{
			success: false,
			msg:     "#not-eq?: too many arguments",
			pattern: `((expression) @capture
 (#not-eq? a b "this"))`,
		},
		{
			success: false,
			msg:     "#not-eq?: need a capture as first argument",
			pattern: `((expression) @capture
 (#not-eq? "a" "this"))`,
		},
		{
			success: true,
			msg:     "#not-eq?: success test",
			pattern: `((expression) @capture
 (#not-eq? @capture "this"))`,
		},
		{
			success: true,
			msg:     "#not-eq?: success test",
			pattern: `((expression) @capture
 (#not-eq? @capture @capture))`,
		},
		{
			success: false,
			msg:     "#is?: too few arguments",
			pattern: `((expression) @capture
 (#is?))`,
		},
		{
			success: false,
			msg:     "#is?: too many arguments",
			pattern: `((expression) @capture
 (#is? a b "this"))`,
		},
		{
			success: false,
			msg:     "#is?: need a string as first argument",
			pattern: `((expression) @capture
 (#is? @capture "this"))`,
		},
		{
			success: false,
			msg:     "#is?: need a string as second argument",
			pattern: `((expression) @capture
 (#is? "this" @capture))`,
		},
		{
			success: true,
			msg:     "#is?: success test",
			pattern: `((expression) @capture
 (#is? "foo" "bar"))`,
		},
		{
			success: false,
			msg:     "#is-not?: too few arguments",
			pattern: `((expression) @capture
 (#is-not?))`,
		},
		{
			success: false,
			msg:     "#is-not?: too many arguments",
			pattern: `((expression) @capture
 (#is-not? a b "this"))`,
		},
		{
			success: false,
			msg:     "#is-not?: need a string as first argument",
			pattern: `((expression) @capture
 (#is-not? @capture "this"))`,
		},
		{
			success: false,
			msg:     "#is-not?: need a string as second argument",
			pattern: `((expression) @capture
 (#is-not? "this" @capture))`,
		},
		{
			success: true,
			msg:     "#is-not?: success test",
			pattern: `((expression) @capture
 (#is-not? "foo" "bar"))`,
		},
		{
			success: false,
			msg:     "#set!: too few arguments",
			pattern: `((expression) @capture
 (#set!))`,
		},
		{
			success: false,
			msg:     "#set!: too many arguments",
			pattern: `((expression) @capture
 (#set! a b "this"))`,
		},
		{
			success: false,
			msg:     "#set!: need a string as first argument",
			pattern: `((expression) @capture
 (#set! @capture "this"))`,
		},
		{
			success: false,
			msg:     "#set!: need a string as second argument",
			pattern: `((expression) @capture
 (#set! "this" @capture))`,
		},
		{
			success: true,
			msg:     "#set!: success test",
			pattern: `((expression) @capture
 (#set! "foo" "bar"))`,
		},
	}

	for _, testCase := range testCases {
		q, err := NewQuery([]byte(testCase.pattern), getTestGrammar())

		if testCase.success {
			assert.Nil(t, err, testCase.msg)
			assert.NotNil(t, q, testCase.msg)
		} else {
			assert.Error(t, err, testCase.msg)
			assert.Nil(t, q, testCase.msg)
		}
	}
}

func TestFilterPredicates(t *testing.T) {
	testCases := []struct {
		input          string
		query          string
		expectedBefore int
		expectedAfter  int
	}{
		{
			input: `// foo`,
			query: `((comment) @capture
  (#match? @capture "^// [a-z]+$"))`,
			expectedBefore: 1,
			expectedAfter:  1,
		},
		{
			input: `// foo123`,
			query: `((comment) @capture
  (#match? @capture "^// [a-z]+$"))`,
			expectedBefore: 1,
			expectedAfter:  0,
		},
		{
			input: `// foo`,
			query: `((comment) @capture
  (#not-match? @capture "^// [a-z]+$"))`,
			expectedBefore: 1,
			expectedAfter:  0,
		},
		{
			input: `// foo123`,
			query: `((comment) @capture
  (#not-match? @capture "^// [a-z]+$"))`,
			expectedBefore: 1,
			expectedAfter:  1,
		},
		{
			input: `// foo`,
			query: `((comment) @capture
  (#eq? @capture "// foo"))`,
			expectedBefore: 1,
			expectedAfter:  1,
		},
		{
			input: `// foo`,
			query: `((comment) @capture
  (#eq? @capture "// bar"))`,
			expectedBefore: 1,
			expectedAfter:  0,
		},
		{
			input: `// foo`,
			query: `((comment) @capture
  (#eq? @capture "// foo") (#eq? @capture "// bar"))`,
			expectedBefore: 1,
			expectedAfter:  0,
		},
		{
			input: `1234 + 1234`,
			query: `((sum
  left: (expression (number) @left)
  right: (expression (number) @right))
  (#eq? @left @right))`,
			expectedBefore: 2,
			expectedAfter:  2,
		},
		{
			input: `1234 + 4321`,
			query: `((sum
  left: (expression (number) @left)
  right: (expression (number) @right))
  (#eq? @left @right))`,
			expectedBefore: 2,
			expectedAfter:  0,
		},
		{
			input: `// foo`,
			query: `((comment) @capture
  (#not-eq? @capture "// foo"))`,
			expectedBefore: 1,
			expectedAfter:  0,
		},
		{
			input: `// foo`,
			query: `((comment) @capture
  (#not-eq? @capture "// bar"))`,
			expectedBefore: 1,
			expectedAfter:  1,
		},
		{
			input: `1234 + 1234`,
			query: `((sum
  left: (expression (number) @left)
  right: (expression (number) @right))
  (#not-eq? @left @right))`,
			expectedBefore: 2,
			expectedAfter:  0,
		},
		{
			input: `1234 + 4321`,
			query: `((sum
  left: (expression (number) @left)
  right: (expression (number) @right))
  (#not-eq? @left @right))`,
			expectedBefore: 2,
			expectedAfter:  2,
		},
		{
			input: `1234 + 4321`,
			query: `((sum
  left: (expression (number) @left)
  right: (expression (number) @right))
  (#eq? @left 1234))`,
			expectedBefore: 2,
			expectedAfter:  2,
		},
		{
			input: `1234 + 4321`,
			query: `((sum
  left: (expression (number) @left)
  right: (expression (number) @right))
  (#eq? @left 1234) (#not-eq? @left @right))`,
			expectedBefore: 2,
			expectedAfter:  2,
		},
		{
			input: `1234 + 4321`,
			query: `((sum
  left: (expression (number) @left)
  right: (expression (number) @right))
  (#eq? @left 1234) (#eq? @left 4321))`,
			expectedBefore: 2,
			expectedAfter:  0,
		},
	}

	parser := NewParser()
	parser.SetLanguage(getTestGrammar())

	for testNum, testCase := range testCases {
		tree := parser.Parse(nil, []byte(testCase.input))
		root := tree.RootNode()

		q, _ := NewQuery([]byte(testCase.query), getTestGrammar())
		qc := NewQueryCursor()
		qc.Exec(q, root)

		before, ok := qc.NextMatch()
		assert.True(t, ok)
		assert.Len(t, before.Captures, testCase.expectedBefore, fmt.Sprintf("test num %d failed", testNum))

		after := qc.FilterPredicates(before, []byte(testCase.input))
		assert.Len(t, after.Captures, testCase.expectedAfter, fmt.Sprintf("test num %d failed", testNum))
	}
}
