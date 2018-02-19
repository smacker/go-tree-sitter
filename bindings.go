package sitter

//#cgo CFLAGS: -g -I${SRCDIR}/tree-sitter/include
//#cgo LDFLAGS: ${SRCDIR}/tree-sitter/out/Release/libruntime.a
//#include "bindings.h"
import "C"
import "unsafe"

// Parse is shortcut for parsing bytes of source code
// return root node and close function
func Parse(content []byte, lang *Language) (*Node, func()) {
	input := (*C.char)(C.CBytes(content))
	doc := C.ts_document_new()
	cLang := (*C.struct_TSLanguage)(lang.Ptr)
	C.ts_document_set_language(doc, cLang)
	C.ts_document_set_input_string(doc, input)
	C.ts_document_parse(doc)
	cNode := C.ts_document_root_node(doc)
	close := func() {
		C.ts_document_free(doc)
	}
	return &Node{cNode, doc}, close
}

type Document struct {
	cDoc *C.struct_TSDocument
}

func NewDocument() *Document {
	cDoc := C.ts_document_new()
	return &Document{cDoc}
}

func (d *Document) Close() {
	C.ts_document_free(d.cDoc)
}

func (d *Document) SetLanguage(lang *Language) {
	cLang := (*C.struct_TSLanguage)(lang.Ptr)
	C.ts_document_set_language(d.cDoc, cLang)
}

func (d *Document) SetInputBytes(content []byte) {
	input := (*C.char)(C.CBytes(content))
	C.ts_document_set_input_string(d.cDoc, input)
}

func (d *Document) Parse() {
	C.ts_document_parse(d.cDoc)
}

func (d *Document) RootNode() *Node {
	cNode := C.ts_document_root_node(d.cDoc)
	return &Node{cNode, d.cDoc}
}

type Language struct {
	Ptr unsafe.Pointer
}

type Node struct {
	cNode C.struct___0
	cDoc  *C.struct_TSDocument
}

func (n *Node) StartByte() uint32 {
	return uint32(C.ts_node_start_byte(n.cNode))
}

func (n *Node) EndByte() uint32 {
	return uint32(C.ts_node_end_byte(n.cNode))
}

func (n *Node) String() string {
	return C.GoString(C.ts_node_string(n.cNode, n.cDoc))
}

func (n *Node) Type() string {
	return C.GoString(C.ts_node_type(n.cNode, n.cDoc))
}

func (n *Node) IsNamed() bool {
	return bool(C.ts_node_is_named(n.cNode))
}

func (n *Node) IsMissing() bool {
	return bool(C.ts_node_is_missing(n.cNode))
}

func (n *Node) HasChanges() bool {
	return bool(C.ts_node_has_changes(n.cNode))
}

func (n *Node) HasError() bool {
	return bool(C.ts_node_has_error(n.cNode))
}

func (n *Node) Parent() *Node {
	cNode := C.ts_node_parent(n.cNode)
	if cNode.data == nil {
		return nil
	}
	return &Node{cNode, n.cDoc}
}

func (n *Node) Child(idx int) *Node {
	cNode := C.ts_node_child(n.cNode, C.uint32_t(idx))
	if cNode.data == nil {
		return nil
	}
	return &Node{cNode, n.cDoc}
}

func (n *Node) NamedChild(idx int) *Node {
	cNode := C.ts_node_named_child(n.cNode, C.uint32_t(idx))
	if cNode.data == nil {
		return nil
	}
	return &Node{cNode, n.cDoc}
}

func (n *Node) ChildCount() uint32 {
	return uint32(C.ts_node_child_count(n.cNode))
}

func (n *Node) NamedChildCount() uint32 {
	return uint32(C.ts_node_named_child_count(n.cNode))
}

func (n *Node) ChildIndex() uint32 {
	return uint32(C.ts_node_child_index(n.cNode))
}

func (n *Node) NextSibling() *Node {
	cNode := C.ts_node_next_sibling(n.cNode)
	if cNode.data == nil {
		return nil
	}
	return &Node{cNode, n.cDoc}
}

func (n *Node) NextNamedSibling() *Node {
	cNode := C.ts_node_next_named_sibling(n.cNode)
	if cNode.data == nil {
		return nil
	}
	return &Node{cNode, n.cDoc}
}

func (n *Node) PrevSibling() *Node {
	cNode := C.ts_node_prev_sibling(n.cNode)
	if cNode.data == nil {
		return nil
	}
	return &Node{cNode, n.cDoc}
}

func (n *Node) PrevNamedSibling() *Node {
	cNode := C.ts_node_prev_named_sibling(n.cNode)
	if cNode.data == nil {
		return nil
	}
	return &Node{cNode, n.cDoc}
}

func (n *Node) Value() string {
	nNode := C.ts_node_named_child(n.cNode, C.uint32_t(0))
	return C.GoString(C.readValue(n.cDoc, nNode))
}
