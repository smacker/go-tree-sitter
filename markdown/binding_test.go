package markdown

import (
	"context"
	"testing"

	sitter "github.com/codepen/go-tree-sitter"
	"github.com/stretchr/testify/assert"
)

func TestGrammar(t *testing.T) {
	assert := assert.New(t)

	code := `
# tree-sitter-markdown

Markdown ([CommonMark Spec v0.29-gfm](https://github.github.com/gfm/)) grammar for [tree-sitter](https://github.com/tree-sitter/tree-sitter)

_Note: This grammar is based on the assumption that **[link label matchings](https://github.github.com/gfm/#matches) will never fail** since reference links can come before their reference definitions, which causes it hard to do incremental parsing without this assumption._

## Install

` + "```" + `sh
npm install tree-sitter-markdown tree-sitter
` + "```" + `

## Usage

` + "```" + `js
const Parser = require("tree-sitter");
const Markdown = require("tree-sitter-markdown");
// (document
//   (atx_heading
//     (atx_heading_marker)
//     (heading_content
//       (text)))
//   (tight_list
//     (list_item
//       (list_marker)
//       (indented_code_block
//         (text))
//       (paragraph
//         (text)))))
` + "```" + `

## License

MIT © [Ika](https://github.com/ikatyang)
	`

	n, err := sitter.ParseCtx(context.Background(), []byte(code), GetLanguage())
	assert.NoError(err)
	assert.Equal(
		"(document (atx_heading (atx_h1_marker) (heading_content (text))) (paragraph (text) (link (link_text (text)) (link_destination (text))) (text) (link (link_text (text)) (link_destination (text)))) (paragraph (emphasis (text) (strong_emphasis (link (link_text (text)) (link_destination (text))) (text)) (text))) (atx_heading (atx_h2_marker) (heading_content (text))) (fenced_code_block (info_string (text)) (code_fence_content (text))) (atx_heading (atx_h2_marker) (heading_content (text))) (fenced_code_block (info_string (text)) (code_fence_content (text) (line_break) (text) (line_break) (text) (line_break) (text) (line_break) (text) (line_break) (text) (line_break) (text) (line_break) (text) (line_break) (text) (line_break) (text) (line_break) (text) (line_break) (text) (line_break) (text) (line_break) (text))) (atx_heading (atx_h2_marker) (heading_content (text))) (paragraph (text) (link (link_text (text)) (link_destination (text)))))",
		n.String(),
	)
}
