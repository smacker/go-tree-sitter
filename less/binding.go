package less

//#include "parser.h"
//TSLanguage *tree_sitter_python();
import "C"

import (
	"unsafe"

	sitter "github.com/codepen/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_less())
	return sitter.NewLanguage(ptr)
}
