package csharp

//#include "tree_sitter/parser.h"
//TSLanguage *tree_sitter_c_sharp();
import "C"
import (
	"unsafe"

	sitter "github.com/smacker/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_c_sharp())
	return sitter.NewLanguage(ptr)
}
