package markdown_test

import (
	"context"
	"testing"

	"github.com/smacker/go-tree-sitter/markdown"
	"github.com/stretchr/testify/assert"
)

func TestMarkdown(t *testing.T) {
	assert := assert.New(t)

	content := "# Hello\n- This is a image: ![image](https://example.com/image.jpg \"a image\")"
	tree, err := markdown.ParseCtx(context.Background(), nil, []byte(content))
	assert.NoError(err)

	assert.Equal(
		"(document (section (atx_heading (atx_h1_marker) heading_content: (inline)) (list (list_item (list_marker_minus) (paragraph (inline))))))",
		tree.BlockTree().RootNode().String(),
	)

	assert.Equal(
		"(inline)",
		tree.InlineTrees()[0].RootNode().String(),
	)

	assert.Equal(
		"(inline (image (image_description) (link_destination) (link_title)))",
		tree.InlineTrees()[1].RootNode().String(),
	)
}

func TestIter(t *testing.T) {
	assert := assert.New(t)

	content := "# Hello\n- This two image: ![image](https://example.com/image.jpg \"a image\"), ![apple](https://example.com/apple.jpg \"a apple\")"
	tree, err := markdown.ParseCtx(context.Background(), nil, []byte(content))
	assert.NoError(err)

	type BlockWithInline struct {
		Node       string
		InlineNode string
	}

	expected := []BlockWithInline{
		{"(document (section (atx_heading (atx_h1_marker) heading_content: (inline)) (list (list_item (list_marker_minus) (paragraph (inline))))))", ""},
		{"(section (atx_heading (atx_h1_marker) heading_content: (inline)) (list (list_item (list_marker_minus) (paragraph (inline)))))", ""},
		{"(atx_heading (atx_h1_marker) heading_content: (inline))", ""},
		{"(atx_h1_marker)", ""},
		{"(inline)", "(inline)"},
		{"(list (list_item (list_marker_minus) (paragraph (inline))))", ""},
		{"(list_item (list_marker_minus) (paragraph (inline)))", ""},
		{"(list_marker_minus)", ""},
		{"(paragraph (inline))", ""},
		{"(inline)", "(inline (image (image_description) (link_destination) (link_title)) (image (image_description) (link_destination) (link_title)))"},
	}

	i := int(0)
	tree.Iter(func(node *markdown.Node) bool {
		assert.Equal(expected[i].Node, node.String(), "node mismatch. idx: %d", i)
		if expected[i].InlineNode != "" || node.Inline != nil {
			assert.Equal(expected[i].InlineNode, node.Inline.String(), "inline node mismatch. idx: %d", i)
		}

		i++
		return true
	})
}

func TestIterStop(t *testing.T) {
	assert := assert.New(t)

	content := "# Hello\n- This two image: ![image](https://example.com/image.jpg \"a image\"), ![apple](https://example.com/apple.jpg \"a apple\")"
	tree, err := markdown.ParseCtx(context.Background(), nil, []byte(content))
	assert.NoError(err)

	type BlockWithInline struct {
		Node       string
		InlineNode string
	}

	expected := []string{
		"(document (section (atx_heading (atx_h1_marker) heading_content: (inline)) (list (list_item (list_marker_minus) (paragraph (inline))))))",
		"(section (atx_heading (atx_h1_marker) heading_content: (inline)) (list (list_item (list_marker_minus) (paragraph (inline)))))",
		"(atx_heading (atx_h1_marker) heading_content: (inline))",
	}

	collected := []string{}
	tree.Iter(func(node *markdown.Node) bool {
		collected = append(collected, node.String())

		if node.Type() == "document" || node.Type() == "section" {
			return true
		}

		return false
	})

	assert.Equal(expected, collected)
}
