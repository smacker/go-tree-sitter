package vue

//#include "parser.h"
//TSLanguage *tree_sitter_vue();
import "C"

import (
	"unsafe"

	sitter "github.com/codepen/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_vue())
	return sitter.NewLanguage(ptr)
}
