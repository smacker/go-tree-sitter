package sparql_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/sparql"
	"github.com/stretchr/testify/assert"
)

const code = `
SELECT * {
	?s ?p ?o
	FILTER (?s > 0)
  }`


const expected = `(unit (select_query (select_clause) (where_clause (group_graph_pattern (triples_block (triples_same_subject subject: (var) (property_list (property (var) (object_list (var)))))) (filter (bracketted_expression (binary_expression (var) (integer))))))))`

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte(code), sparql.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		expected,
		n.String(),
	)
}
