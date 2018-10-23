package javascript

//#cgo LDFLAGS: ${SRCDIR}/../vendor/tree-sitter-javascript/parser.o
//#cgo LDFLAGS: ${SRCDIR}/../vendor/tree-sitter-javascript/scanner.o
//#cgo CFLAGS: -I${SRCDIR}/../vendor/tree-sitter-javascript/src
//#include "tree_sitter/parser.h"
//TSLanguage *tree_sitter_javascript();
import "C"
import (
	"unsafe"

	sitter "github.com/smacker/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_javascript())
	return sitter.NewLanguage(ptr)
}
