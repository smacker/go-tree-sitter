package json

import (
	"context"
	"testing"

	sitter "github.com/codepen/go-tree-sitter"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	code := `
	{
		"name": "test",
		"version": "1.0.0",
		"scripts": {
			"run": "yarn run"
		},
		"license": "ISC",
		"homepage": "https://test.com",
		"devDependencies": {
			"typescript": "^4.4.4"
		},
		"dependencies": {
			"@svgr/cli": "^5.5.0",
			"react": "^17.0.2"
		},
		"private": true
	}
	`

	n, err := sitter.ParseCtx(context.Background(), []byte(code), GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(document (object (pair key: (string (string_content)) value: (string (string_content))) (pair key: (string (string_content)) value: (string (string_content))) (pair key: (string (string_content)) value: (object (pair key: (string (string_content)) value: (string (string_content))))) (pair key: (string (string_content)) value: (string (string_content))) (pair key: (string (string_content)) value: (string (string_content))) (pair key: (string (string_content)) value: (object (pair key: (string (string_content)) value: (string (string_content))))) (pair key: (string (string_content)) value: (object (pair key: (string (string_content)) value: (string (string_content))) (pair key: (string (string_content)) value: (string (string_content))))) (pair key: (string (string_content)) value: (true))))",
		n.String(),
	)
}
