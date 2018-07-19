package javascript

//#cgo CFLAGS: -I${SRCDIR}/tree-sitter-javascript/src
//#include "parser.c"
//#include "scanner.c"
import "C"
import (
	"unsafe"

	sitter "github.com/smacker/go-tree-sitter"
)

func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_javascript())
	return sitter.NewLanguage(ptr)
}
