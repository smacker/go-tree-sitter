package python

//#cgo LDFLAGS: ${SRCDIR}/../vendor/tree-sitter-python/parser.o
//#cgo LDFLAGS: ${SRCDIR}/../vendor/tree-sitter-python/scanner.o
//#cgo LDFLAGS: -lstdc++
//#cgo CFLAGS: -I${SRCDIR}/../vendor/tree-sitter-python/src
//#include <stdlib.h>
//#include "tree_sitter/parser.h"
//TSLanguage *tree_sitter_python();
import "C"
import (
	"unsafe"

	sitter "github.com/smacker/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_python())
	return sitter.NewLanguage(ptr)
}
