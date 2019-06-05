package java

//#cgo LDFLAGS: ${SRCDIR}/../vendor/java/parser.o
//#cgo CFLAGS: -I${SRCDIR}/../vendor/tree-sitter/lib/include
//#include "tree_sitter/parser.h"
//TSLanguage *tree_sitter_java();
import "C"
import (
	"unsafe"

	sitter "github.com/smacker/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_java())
	return sitter.NewLanguage(ptr)
}
