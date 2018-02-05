package sitter

//#cgo CFLAGS: -g -I${SRCDIR}/tree-sitter/include
//#cgo LDFLAGS: ${SRCDIR}/tree-sitter/out/Release/obj.target/libruntime.a
//#include "bindings.h"
import "C"

type Node struct {
	cNode C.struct___0
	cDoc  *C.struct_TSDocument
}

func (n *Node) String() string {
	return C.GoString(C.ts_node_string(n.cNode, n.cDoc))
}

func (n *Node) Type() string {
	return C.GoString(C.ts_node_type(n.cNode, n.cDoc))
}

func (n *Node) Children() int {
	return int(C.ts_node_child_count(n.cNode))
}

func (n *Node) Name() string {
	if n.Type() != "function" {
		return ""
	}
	nNode := C.ts_node_named_child(n.cNode, C.uint32_t(0))
	return C.GoString(C.readValue(n.cDoc, nNode))
}

func (n *Node) Child(idx int) *Node {
	cNode := C.ts_node_child(n.cNode, C.uint32_t(idx))
	return &Node{cNode, n.cDoc}
}

func Parse(content []byte, lang string) *Node {
	input := (*C.char)(C.CBytes(content))
	doc := C.ts_document_new()
	switch lang {
	case "javascript":
		cNode := C.parse_javascript(doc, input)
		return &Node{cNode, doc}
	default:
		panic("language not found")
	}
}
