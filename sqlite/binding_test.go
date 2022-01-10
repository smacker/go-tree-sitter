package sqlite_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/sqlite"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	code := `SELECT * FROM table LIMIT 1;`

	n, err := sitter.ParseCtx(context.Background(), []byte(code), sqlite.GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(sql_stmt_list (sql_stmt (select_stmt (SELECT) (from_clause (FROM) (table_or_subquery (identifier))) (limit_clause (LIMIT) (numeric_literal)))))",
		n.String(),
	)
}
