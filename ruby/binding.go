package ruby

//#cgo LDFLAGS: ${SRCDIR}/../vendor/tree-sitter-ruby/parser.o
//#cgo LDFLAGS: ${SRCDIR}/../vendor/tree-sitter-ruby/scanner.o
//#cgo LDFLAGS: -lstdc++
//#cgo CFLAGS: -I${SRCDIR}/../vendor/tree-sitter-ruby/src
//#include "tree_sitter/parser.h"
//TSLanguage *tree_sitter_ruby();
import "C"
import (
	"unsafe"

	sitter "github.com/smacker/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_ruby())
	return sitter.NewLanguage(ptr)
}
