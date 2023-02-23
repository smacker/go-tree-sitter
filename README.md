# go tree-sitter

[![Build Status](https://github.com/smacker/go-tree-sitter/workflows/Test/badge.svg?branch=master)](https://github.com/smacker/go-tree-sitter/actions/workflows/test.yml?query=branch%3Amaster)
[![GoDoc](https://godoc.org/github.com/smacker/go-tree-sitter?status.svg)](https://godoc.org/github.com/smacker/go-tree-sitter)

Golang bindings for [tree-sitter](https://github.com/tree-sitter/tree-sitter)

## Usage

Create a parser with that grammar:

```go
import (
	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/javascript"
)

parser := sitter.NewParser()
parser.SetLanguage(javascript.GetLanguage())
```

Parse some code:

```go
sourceCode := []byte("let a = 1")
tree := parser.Parse(nil, sourceCode)
```

Inspect the syntax tree:

```go
n := tree.RootNode()

fmt.Println(n) // (program (lexical_declaration (variable_declarator (identifier) (number))))

child := n.NamedChild(0)
fmt.Println(child.Type()) // lexical_declaration
fmt.Println(child.StartByte()) // 0
fmt.Println(child.EndByte()) // 9
```

### Editing

If your source code changes, you can update the syntax tree. This will take less time than the first parse.

```go
// change 1 -> true
newText := []byte("let a = true")
tree.Edit(sitter.EditInput{
    StartIndex:  8,
    OldEndIndex: 9,
    NewEndIndex: 12,
    StartPoint: sitter.Point{
        Row:    0,
        Column: 8,
    },
    OldEndPoint: sitter.Point{
        Row:    0,
        Column: 9,
    },
    NewEndPoint: sitter.Point{
        Row:    0,
        Column: 12,
    },
})

// check that it changed tree
assert.True(n.HasChanges())
assert.True(n.Child(0).HasChanges())
assert.False(n.Child(0).Child(0).HasChanges()) // left side of the tree didn't change
assert.True(n.Child(0).Child(1).HasChanges())

// generate new tree
newTree := parser.Parse(tree, newText)
```

### Predicates

You can filter AST by using [predicate](https://tree-sitter.github.io/tree-sitter/using-parsers#predicates) S-expressions.

Similar to [Rust](https://github.com/tree-sitter/tree-sitter/tree/master/lib/binding_rust) or [WebAssembly](https://github.com/tree-sitter/tree-sitter/blob/master/lib/binding_web) bindings we support filtering on a few common predicates:
- `eq?`, `not-eq?`
- `match?`, `not-match?`

Usage [example](./_examples/predicates/main.go):

```go
func main() {
    // Javascript code
	sourceCode := []byte(`
		const camelCaseConst = 1;
		const SCREAMING_SNAKE_CASE_CONST = 2;
		const lower_snake_case_const = 3;`)
	// Query with predicates
	screamingSnakeCasePattern := `(
		(identifier) @constant
		(#match? @constant "^[A-Z][A-Z_]+")
	)`

	// Parse source code
	lang := javascript.GetLanguage()
	n, _ := sitter.ParseCtx(context.Background(), sourceCode, lang)
	// Execute the query
	q, _ := sitter.NewQuery([]byte(screamingSnakeCasePattern), lang)
	qc := sitter.NewQueryCursor()
	qc.Exec(q, n)
	// Iterate over query results
	for {
		m, ok := qc.NextMatch()
		if !ok {
			break
		}
		// Apply predicates filtering
		m = qc.FilterPredicates(m, sourceCode)
		for _, c := range m.Captures {
			fmt.Println(c.Node.Content(sourceCode))
		}
	}
}

// Output of this program:
// SCREAMING_SNAKE_CASE_CONST
```

## Development

Check if any updates for vendored files are available:

```
./vendor.sh check-updates
```

Update vendor files:

- modify `grammars` array in `vendor.sh`
- run `./vendor.sh download`.  (This script requires Bash v5, not the v3 of recent Mac OS.)
