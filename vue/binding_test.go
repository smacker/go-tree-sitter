package vue

import (
	"context"
	"testing"

	sitter "github.com/codepen/go-tree-sitter"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	code := `
<script>
export default {
	data() {
		return {
			greeting: 'Hello World!'
		}
	}
}
</script>

<template>
	<p class="greeting">{{ greeting }}</p>
</template>

<style>
.greeting {
	color: red;
	font-weight: bold;
}
</style>
	`

	n, err := sitter.ParseCtx(context.Background(), []byte(code), GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(component (script_element (start_tag (tag_name)) (raw_text) (end_tag (tag_name))) (template_element (start_tag (tag_name)) (text) (element (start_tag (tag_name) (attribute (attribute_name) (quoted_attribute_value (attribute_value)))) (interpolation (raw_text)) (end_tag (tag_name))) (text) (end_tag (tag_name))) (style_element (start_tag (tag_name)) (raw_text) (end_tag (tag_name))))",
		n.String(),
	)
}
