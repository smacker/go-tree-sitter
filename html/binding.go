package html

//#include "parser.h"
//TSLanguage *tree_sitter_html();
import "C"

import (
	"unsafe"

	sitter "github.com/codepen/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_html())
	return sitter.NewLanguage(ptr)
}
