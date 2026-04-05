package apex

//#include "parser.h"
//TSLanguage *tree_sitter_apex();
import "C"
import (
	"unsafe"

	sitter "github.com/smacker/go-tree-sitter"
)

// GetLanguage returns the Apex tree-sitter language.
// Generated from tree-sitter-sfapex commit 3597575a4297 (2025-02-13, v2.4.1).
// https://github.com/aheber/tree-sitter-sfapex
func GetLanguage() *sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_apex())
	return sitter.NewLanguage(ptr)
}
