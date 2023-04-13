package main

import (
	"context"
	"fmt"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/javascript"
)

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
