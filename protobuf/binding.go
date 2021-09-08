package protobuf

//#include "parser.h"
//TSLanguage *tree_sitter_go();
import "C"
import (
	"unsafe"

	sitter "github.com/colinwm/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_proto())
	return sitter.NewLanguage(ptr)
}
