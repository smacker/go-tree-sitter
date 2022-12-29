package markdown

//#include "parser.h"
//TSLanguage *tree_sitter_markdown();
import "C"

import (
	"unsafe"

	sitter "github.com/codepen/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_markdown())
	return sitter.NewLanguage(ptr)
}
