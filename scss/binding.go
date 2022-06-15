package scss

//#include "parser.h"
//TSLanguage *tree_sitter_scss();
import "C"

import (
	"unsafe"

	sitter "github.com/codepen/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_scss())
	return sitter.NewLanguage(ptr)
}
