package apex_test

import (
	"context"
	"testing"

	sitter "github.com/smacker/go-tree-sitter"
	"github.com/smacker/go-tree-sitter/apex"
	"github.com/stretchr/testify/assert"
)

func TestApexClass(t *testing.T) {
	code := []byte(`public class AccountService {
    public Account getAccount(Id accountId) {
        return [SELECT Id, Name FROM Account WHERE Id = :accountId];
    }
}`)
	n, err := sitter.ParseCtx(context.Background(), code, apex.GetLanguage())
	assert.Nil(t, err)
	assert.Equal(t, "parser_output", n.Type())
	assert.True(t, n.ChildCount() > 0)
	assert.Equal(t, "class_declaration", n.Child(0).Type())
}

func TestApexTrigger(t *testing.T) {
	code := []byte(`trigger AccountTrigger on Account (before insert, before update) {
    for (Account acc : Trigger.new) {
        acc.Name = acc.Name.toUpperCase();
    }
}`)
	n, err := sitter.ParseCtx(context.Background(), code, apex.GetLanguage())
	assert.Nil(t, err)
	assert.True(t, n.ChildCount() > 0)
}
