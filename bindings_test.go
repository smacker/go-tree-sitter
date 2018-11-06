package sitter_test

import (
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/javascript"
	"github.com/stretchr/testify/assert"
)

func TestRootNode(t *testing.T) {
	assert := assert.New(t)

	n := sitter.Parse([]byte("let a = 1"), javascript.GetLanguage())

	assert.Equal(uint32(0), n.StartByte())
	assert.Equal(uint32(9), n.EndByte())
	assert.Equal(sitter.Point{
		Row:    0,
		Column: 0,
	}, n.StartPoint())
	assert.Equal(sitter.Point{
		Row:    0,
		Column: 9,
	}, n.EndPoint())
	assert.Equal("(program (lexical_declaration (variable_declarator (identifier) (number))))", n.String())
	assert.Equal("program", n.Type())
	assert.Equal(sitter.Symbol(115), n.Symbol())

	assert.Equal(false, n.IsNull())
	assert.Equal(true, n.IsNamed())
	assert.Equal(false, n.IsMissing())
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
}

func TestTree(t *testing.T) {
	assert := assert.New(t)

	parser := sitter.NewParser()

	parser.Debug()
	parser.SetLanguage(javascript.GetLanguage())
	tree := parser.Parse([]byte("let a = 1"))
	n := tree.RootNode()

	assert.Equal(uint32(0), n.StartByte())
	assert.Equal(uint32(9), n.EndByte())
	assert.Equal("program", n.Type())
	assert.Equal("(program (lexical_declaration (variable_declarator (identifier) (number))))", n.String())

	tree2 := parser.Parse([]byte("let a = 'a'"))
	n = tree2.RootNode()
	assert.Equal("(program (lexical_declaration (variable_declarator (identifier) (string))))", n.String())

	// change 'a' -> true
	newText := []byte("let a = true")
	tree2.Edit(sitter.EditInput{
		StartIndex:  8,
		OldEndIndex: 11,
		NewEndIndex: 12,
		StartPoint: sitter.Point{
			Row:    0,
			Column: 8,
		},
		OldEndPoint: sitter.Point{
			Row:    0,
			Column: 11,
		},
		NewEndPoint: sitter.Point{
			Row:    0,
			Column: 12,
		},
	})
	// check that it changed tree
	assert.True(n.HasChanges())
	assert.True(n.Child(0).HasChanges())
	assert.False(n.Child(0).Child(0).HasChanges()) // left side of tree didn't change
	assert.True(n.Child(0).Child(1).HasChanges())

	tree3 := parser.ParseWithTree(newText, tree2)
	n = tree3.RootNode()
	assert.Equal("(program (lexical_declaration (variable_declarator (identifier) (true))))", n.String())
}

func TestLanguage(t *testing.T) {
	assert := assert.New(t)
	js := javascript.GetLanguage()

	assert.True(js.SymbolCount() > 169)
	assert.Equal(js.SymbolName(169), "function")
	assert.Equal(js.SymbolType(169), sitter.SymbolTypeRegular)

	assert.Equal(sitter.SymbolTypeRegular.String(), "Regular")
}
