package golang

//#cgo CFLAGS: -std=c99 -I${SRCDIR}/../vendor/tree-sitter-go/src
//#include "parser.c"
import "C"
import (
	"unsafe"

	sitter "github.com/smacker/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_go())
	return sitter.NewLanguage(ptr)
}
