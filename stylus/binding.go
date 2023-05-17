package stylus

//#include "parser.h"
//TSLanguage *tree_sitter_stylus();
import "C"

import (
	"unsafe"

	sitter "github.com/codepen/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_stylus())
	return sitter.NewLanguage(ptr)
}
