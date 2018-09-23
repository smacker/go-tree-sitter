package sitter

//#cgo CFLAGS: -g -I${SRCDIR}/vendor/tree-sitter/include
//#cgo LDFLAGS: ${SRCDIR}/vendor/tree-sitter/out/Release/libruntime.a
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

	return &ptr, close
}

type Parser = C.TSParser

func NewParser() *Parser {
	cParser := C.ts_parser_new()
	return cParser
}

func (p *Parser) Delete() {
	C.ts_parser_delete(p)
}

func (p *Parser) SetLanguage(lang *Language) {
	cLang := (*C.struct_TSLanguage)(lang.ptr)
	C.ts_parser_set_language(p, cLang)
}

func (p *Parser) Parse(content []byte) *Tree {
	return p.ParseWithTree(content, nil)
}

func (p *Parser) ParseWithTree(content []byte, t *Tree) *Tree {
	input := (*C.char)(C.CBytes(content))
	treePtr := C.ts_parser_parse_string(p, t, input, C.uint32_t(len(content)))

	return treePtr
}

func (p *Parser) ReParse(t *Tree, input *Input) *Tree {
	treePtr := C.ts_parser_parse(p, t, *input.ptr)

	return treePtr
}

func (p *Parser) Debug() {
	logger := C.stderr_logger_new(true)
	C.ts_parser_set_logger(p, logger)
}

type Tree = C.TSTree

func (t *Tree) Delete() {
	C.ts_tree_delete(t)
}

func (t *Tree) RootNode() *Node {
	ptr := C.ts_tree_root_node(t)
	return &ptr
}

func getTSPoint(text string) C.TSPoint {
	var row, col int
	for _, b := range text {
		if b == '\n' {
			row++
			col = 0
		} else {
			col++
		}
	}
	return C.TSPoint{
		row:    C.uint32_t(row),
		column: C.uint32_t(col),
	}
}

type Input struct {
	ptr *C.TSInput
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
	cEditInput := &C.TSInputEdit{
		start_byte:   C.uint32_t(i.StartIndex),
		old_end_byte: C.uint32_t(i.OldEndIndex),
		new_end_byte: C.uint32_t(i.NewEndIndex),
		start_point: C.TSPoint{
			row:    C.uint32_t(i.StartPosition.Row),
			column: C.uint32_t(i.StartPosition.Column),
		},
		old_end_point: C.TSPoint{
			row:    C.uint32_t(i.OldEndPosition.Row),
			column: C.uint32_t(i.OldEndPosition.Column),
		},
		new_end_point: C.TSPoint{
			row:    C.uint32_t(i.NewEndPosition.Row),
			column: C.uint32_t(i.NewEndPosition.Column),
		},
	}

	C.ts_tree_edit(t, cEditInput)
}

type Language struct {
	ptr unsafe.Pointer
}

func NewLanguage(ptr unsafe.Pointer) *Language {
	return &Language{ptr}
}

type Node = C.TSNode

func (n Node) StartByte() uint32 {
	return uint32(C.ts_node_start_byte(n))
}

func (n Node) EndByte() uint32 {
	return uint32(C.ts_node_end_byte(n))
}

func (n Node) String() string {
	return C.GoString(C.ts_node_string(n))
}

func (n Node) Type() string {
	return C.GoString(C.ts_node_type(n))
}

func (n Node) IsNamed() bool {
	return bool(C.ts_node_is_named(n))
}

func (n Node) IsMissing() bool {
	return bool(C.ts_node_is_missing(n))
}

func (n Node) HasChanges() bool {
	return bool(C.ts_node_has_changes(n))
}

func (n Node) HasError() bool {
	return bool(C.ts_node_has_error(n))
}

func (n Node) Parent() *Node {
	nn := C.ts_node_parent(n)
	if nn.id == nil {
		return nil
	}
	return &nn
}

func (n Node) Child(idx int) *Node {
	nn := C.ts_node_child(n, C.uint32_t(idx))
	if nn.id == nil {
		return nil
	}
	return &nn
}

func (n Node) NamedChild(idx int) *Node {
	nn := C.ts_node_named_child(n, C.uint32_t(idx))
	if nn.id == nil {
		return nil
	}
	return &nn
}

func (n Node) ChildCount() uint32 {
	return uint32(C.ts_node_child_count(n))
}

func (n Node) NamedChildCount() uint32 {
	return uint32(C.ts_node_named_child_count(n))
}

func (n Node) NextSibling() *Node {
	nn := C.ts_node_next_sibling(n)
	if nn.id == nil {
		return nil
	}
	return &nn
}

func (n Node) NextNamedSibling() *Node {
	nn := C.ts_node_next_named_sibling(n)
	if nn.id == nil {
		return nil
	}
	return &nn
}

func (n Node) PrevSibling() *Node {
	nn := C.ts_node_prev_sibling(n)
	if nn.id == nil {
		return nil
	}
	return &nn
}

func (n Node) PrevNamedSibling() *Node {
	nn := C.ts_node_prev_named_sibling(n)
	if nn.id == nil {
		return nil
	}
	return &nn
}
