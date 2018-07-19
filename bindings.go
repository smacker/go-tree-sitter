package sitter

//#cgo CFLAGS: -g -I${SRCDIR}/tree-sitter/include
//#cgo LDFLAGS: ${SRCDIR}/tree-sitter/out/Release/libruntime.a
//#include "bindings.h"
import "C"
import (
	"unsafe"
)

// Parse is shortcut for parsing bytes of source code
// return root node and close function
func Parse(content []byte, lang *Language) (*Node, func()) {
	input := (*C.char)(C.CBytes(content))

	cParser := C.ts_parser_new()
	cLang := (*C.struct_TSLanguage)(lang.ptr)
	C.ts_parser_set_language(cParser, cLang)

	cTree := C.ts_parser_parse_string(cParser, nil, input, C.uint32_t(len(content)))
	ptr := C.ts_tree_root_node(cTree)

	close := func() {
		C.ts_tree_delete(cTree)
		C.ts_parser_delete(cParser)
	}

	return &Node{ptr}, close
}

type Parser struct {
	ptr *C.TSParser
}

func NewParser() *Parser {
	cParser := C.ts_parser_new()
	return &Parser{cParser}
}

func (p *Parser) Delete() {
	C.ts_parser_delete(p.ptr)
}

func (p *Parser) SetLanguage(lang *Language) {
	cLang := (*C.struct_TSLanguage)(lang.ptr)
	C.ts_parser_set_language(p.ptr, cLang)
}

func (p *Parser) Parse(content []byte) *Tree {
	return p.ParseWithTree(content, nil)
}

func (p *Parser) ParseWithTree(content []byte, t *Tree) *Tree {
	input := (*C.char)(C.CBytes(content))

	var oldTreePtr *C.TSTree
	if t == nil {
		oldTreePtr = nil
	} else {
		oldTreePtr = t.ptr
	}

	treePtr := C.ts_parser_parse_string(p.ptr, oldTreePtr, input, C.uint32_t(len(content)))

	return &Tree{treePtr}
}

func (p *Parser) ReParse(t *Tree, input *Input) *Tree {
	treePtr := C.ts_parser_parse(p.ptr, t.ptr, *input.ptr)

	return &Tree{treePtr}
}

func (p *Parser) Debug() {
	logger := C.stderr_logger_new(true)
	C.ts_parser_set_logger(p.ptr, logger)
}

type Tree struct {
	ptr *C.TSTree
}

func (t *Tree) Delete() {
	C.ts_tree_delete(t.ptr)
}

func (t *Tree) RootNode() *Node {
	ptr := C.ts_tree_root_node(t.ptr)
	return &Node{ptr}
}

func getTSPoint(text string) C.struct___4 {
	var row, col int
	for _, b := range text {
		if b == '\n' {
			row++
			col = 0
		} else {
			col++
		}
	}
	// C.struct_TSPoint???
	return C.struct___4{
		row:    C.uint32_t(row),
		column: C.uint32_t(col),
	}
}

type Input struct {
	ptr *C.struct___2
	str string
}

type Position struct {
	Row    int
	Column int
}

type EditInput struct {
	StartIndex     int
	OldEndIndex    int
	NewEndIndex    int
	StartPosition  Position
	OldEndPosition Position
	NewEndPosition Position
}

func (t *Tree) Edit(i EditInput) {
	// FIXME why isn't it C.struct_TSInputEdit?
	cEditInput := &C.struct___3{
		start_byte:   C.uint32_t(i.StartIndex),
		old_end_byte: C.uint32_t(i.OldEndIndex),
		new_end_byte: C.uint32_t(i.NewEndIndex),
		start_point: C.struct___4{
			row:    C.uint32_t(i.StartPosition.Row),
			column: C.uint32_t(i.StartPosition.Column),
		},
		old_end_point: C.struct___4{
			row:    C.uint32_t(i.OldEndPosition.Row),
			column: C.uint32_t(i.OldEndPosition.Column),
		},
		new_end_point: C.struct___4{
			row:    C.uint32_t(i.NewEndPosition.Row),
			column: C.uint32_t(i.NewEndPosition.Column),
		},
	}

	C.ts_tree_edit(t.ptr, cEditInput)
}

type Language struct {
	ptr unsafe.Pointer
}

func NewLanguage(ptr unsafe.Pointer) *Language {
	return &Language{ptr}
}

type Node struct {
	ptr C.TSNode
}

func (n *Node) StartByte() uint32 {
	return uint32(C.ts_node_start_byte(n.ptr))
}

func (n *Node) EndByte() uint32 {
	return uint32(C.ts_node_end_byte(n.ptr))
}

func (n *Node) String() string {
	return C.GoString(C.ts_node_string(n.ptr))
}

func (n *Node) Type() string {
	return C.GoString(C.ts_node_type(n.ptr))
}

func (n *Node) IsNamed() bool {
	return bool(C.ts_node_is_named(n.ptr))
}

func (n *Node) IsMissing() bool {
	return bool(C.ts_node_is_missing(n.ptr))
}

func (n *Node) HasChanges() bool {
	return bool(C.ts_node_has_changes(n.ptr))
}

func (n *Node) HasError() bool {
	return bool(C.ts_node_has_error(n.ptr))
}

func (n *Node) Parent() *Node {
	ptr := C.ts_node_parent(n.ptr)
	if ptr.id == nil {
		return nil
	}
	return &Node{ptr}
}

func (n *Node) Child(idx int) *Node {
	ptr := C.ts_node_child(n.ptr, C.uint32_t(idx))
	if ptr.id == nil {
		return nil
	}
	return &Node{ptr}
}

func (n *Node) NamedChild(idx int) *Node {
	ptr := C.ts_node_named_child(n.ptr, C.uint32_t(idx))
	if ptr.id == nil {
		return nil
	}
	return &Node{ptr}
}

func (n *Node) ChildCount() uint32 {
	return uint32(C.ts_node_child_count(n.ptr))
}

func (n *Node) NamedChildCount() uint32 {
	return uint32(C.ts_node_named_child_count(n.ptr))
}

func (n *Node) NextSibling() *Node {
	ptr := C.ts_node_next_sibling(n.ptr)
	if ptr.id == nil {
		return nil
	}
	return &Node{ptr}
}

func (n *Node) NextNamedSibling() *Node {
	ptr := C.ts_node_next_named_sibling(n.ptr)
	if ptr.id == nil {
		return nil
	}
	return &Node{ptr}
}

func (n *Node) PrevSibling() *Node {
	ptr := C.ts_node_prev_sibling(n.ptr)
	if ptr.id == nil {
		return nil
	}
	return &Node{ptr}
}

func (n *Node) PrevNamedSibling() *Node {
	ptr := C.ts_node_prev_named_sibling(n.ptr)
	if ptr.id == nil {
		return nil
	}
	return &Node{ptr}
}
