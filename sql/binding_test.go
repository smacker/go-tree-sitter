package sql_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/sql"
	"github.com/stretchr/testify/assert"
)

const code = `SELECT * FROM my_table
WHERE count > 1
ORDER BY time DESC
LIMIT 5;`

const expected = `(program (statement (select (keyword_select) (select_expression (term value: (all_fields)))) (from (keyword_from) (relation (object_reference name: (identifier))) (where (keyword_where) predicate: (binary_expression left: (field name: (identifier)) right: (literal))) (order_by (keyword_order) (keyword_by) (order_target (field name: (identifier)) (direction (keyword_desc)))) (limit (keyword_limit) (literal)))))`

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte(code), sql.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		expected,
		n.String(),
	)
}
