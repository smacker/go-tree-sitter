package java

//#cgo CFLAGS: -std=c99 -I${SRCDIR}/../vendor/tree-sitter-java/src
//#include "parser.c"
import "C"
import (
	"unsafe"

	sitter "github.com/smacker/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_java())
	return sitter.NewLanguage(ptr)
}
