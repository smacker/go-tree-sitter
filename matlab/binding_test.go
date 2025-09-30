package matlab_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/matlab"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	n, err := sitter.ParseCtx(context.Background(), []byte("function result = myFunction(x)\n  result = x * 2;\nend"), matlab.GetLanguage())
	assert.NoError(err)
	assert.NotNil(n)
	assert.Contains(n.String(), "function")
}
