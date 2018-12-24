package sitter

//#cgo CFLAGS: -g -I${SRCDIR}/vendor/tree-sitter/include
//#cgo LDFLAGS: ${SRCDIR}/vendor/tree_sitter.a
//#include "bindings.h"
import "C"
import (
	"runtime"
	"unsafe"
)

// Parse is shortcut for parsing bytes of source code
// return root node and close function
func Parse(content []byte, lang *Language) *Node {
	input := (*C.char)(C.CBytes(content))

	cParser := C.ts_parser_new()
	cLang := (*C.struct_TSLanguage)(lang.ptr)
	C.ts_parser_set_language(cParser, cLang)

	cTree := C.ts_parser_parse_string(cParser, nil, input, C.uint32_t(len(content)))
	ptr := C.ts_tree_root_node(cTree)

	return &Node{ptr, &Tree{cTree}}
}

// Parser produces concrete syntax tree based on source code using Language
type Parser struct{ c *C.TSParser }

// NewParser creates new Parser
func NewParser() *Parser {
	p := &Parser{C.ts_parser_new()}
	runtime.SetFinalizer(p, deleteParser)
	return p
}

// SetLanguage assignes Language to a parser
func (p *Parser) SetLanguage(lang *Language) {
	cLang := (*C.struct_TSLanguage)(lang.ptr)
	C.ts_parser_set_language(p.c, cLang)
}

// Parse produces new Tree from content
func (p *Parser) Parse(content []byte) *Tree {
	return p.ParseWithTree(content, nil)
}

// ParseWithTree produces new Tree from content using old tree
func (p *Parser) ParseWithTree(content []byte, t *Tree) *Tree {
	var cTree *C.TSTree
	if t != nil {
		cTree = t.c
	}

	input := (*C.char)(C.CBytes(content))
	newTree := &Tree{C.ts_parser_parse_string(p.c, cTree, input, C.uint32_t(len(content)))}
	runtime.SetFinalizer(newTree, deleteTree)
	return newTree
}

// OperationLimit returns current operatation limit of the tree
func (p *Parser) OperationLimit() int {
	return int(C.ts_parser_operation_limit(p.c))
}

// SetOperationLimit limits the amount of work the parser does on any given call to parse()
func (p *Parser) SetOperationLimit(limit int) {
	C.ts_parser_set_operation_limit(p.c, C.ulong(limit))
}

// Debug enables debug output to stderr
func (p *Parser) Debug() {
	logger := C.stderr_logger_new(true)
	C.ts_parser_set_logger(p.c, logger)
}

func deleteParser(p *Parser) {
	C.ts_parser_delete(p.c)
}

// Tree represents the syntax tree of an entire source code file
// Note: Tree instances are not thread safe;
// you must copy a tree if you want to use it on multiple threads simultaneously.
type Tree struct{ c *C.TSTree }

// Copy returns a new copy of a tree
func (t *Tree) Copy() *Tree {
	newTree := &Tree{C.ts_tree_copy(t.c)}
	runtime.SetFinalizer(newTree, deleteTree)
	return newTree
}

// RootNode returns root node of a tree
func (t *Tree) RootNode() *Node {
	ptr := C.ts_tree_root_node(t.c)
	return &Node{ptr, t}
}

func deleteTree(t *Tree) {
	C.ts_tree_delete(t.c)
}

type Point struct {
	Row    uint32
	Column uint32
}

type EditInput struct {
	StartIndex  uint32
	OldEndIndex uint32
	NewEndIndex uint32
	StartPoint  Point
	OldEndPoint Point
	NewEndPoint Point
}

func (t *Tree) Edit(i EditInput) {
	cEditInput := &C.TSInputEdit{
		start_byte:   C.uint32_t(i.StartIndex),
		old_end_byte: C.uint32_t(i.OldEndIndex),
		new_end_byte: C.uint32_t(i.NewEndIndex),
		start_point: C.TSPoint{
			row:    C.uint32_t(i.StartPoint.Row),
			column: C.uint32_t(i.StartPoint.Column),
		},
		old_end_point: C.TSPoint{
			row:    C.uint32_t(i.OldEndPoint.Row),
			column: C.uint32_t(i.OldEndPoint.Column),
		},
		new_end_point: C.TSPoint{
			row:    C.uint32_t(i.OldEndPoint.Row),
			column: C.uint32_t(i.OldEndPoint.Column),
		},
	}

	C.ts_tree_edit(t.c, cEditInput)
}

// Language defines how to parse a particular programming language
type Language struct {
	ptr unsafe.Pointer
}

// NewLanguage creates new Language from c pointer
func NewLanguage(ptr unsafe.Pointer) *Language {
	return &Language{ptr}
}

func (l *Language) SymbolName(s Symbol) string {
	return C.GoString(C.ts_language_symbol_name((*C.TSLanguage)(l.ptr), s))
}

func (l *Language) SymbolType(s Symbol) SymbolType {
	return SymbolType(C.ts_language_symbol_type((*C.TSLanguage)(l.ptr), s))
}

func (l *Language) SymbolCount() uint32 {
	return uint32(C.ts_language_symbol_count((*C.TSLanguage)(l.ptr)))
}

// Node represents a single node in the syntax tree
// It tracks its start and end positions in the source code,
// as well as its relation to other nodes like its parent, siblings and children.
type Node struct {
	c C.TSNode
	t *Tree // keep pointer on tree becase node is valid only as long as tree is
}

type Symbol = C.TSSymbol

type SymbolType int

const (
	SymbolTypeRegular SymbolType = iota
	SymbolTypeAnonymous
	SymbolTypeAuxiliary
)

var symbolTypeNames = []string{
	"Regular",
	"Anonymous",
	"Auxiliary",
}

func (t SymbolType) String() string {
	return symbolTypeNames[t]
}

func (n Node) StartByte() uint32 {
	return uint32(C.ts_node_start_byte(n.c))
}

func (n Node) EndByte() uint32 {
	return uint32(C.ts_node_end_byte(n.c))
}

func (n Node) StartPoint() Point {
	p := C.ts_node_start_point(n.c)
	return Point{
		Row:    uint32(p.row),
		Column: uint32(p.column),
	}
}

func (n Node) EndPoint() Point {
	p := C.ts_node_end_point(n.c)
	return Point{
		Row:    uint32(p.row),
		Column: uint32(p.column),
	}
}

func (n Node) Symbol() Symbol {
	return C.ts_node_symbol(n.c)
}

func (n Node) Type() string {
	return C.GoString(C.ts_node_type(n.c))
}

func (n Node) String() string {
	ptr := C.ts_node_string(n.c)
	defer C.free(unsafe.Pointer(ptr))
	return C.GoString(ptr)
}

func (n Node) Equal(other Node) bool {
	return bool(C.ts_node_eq(n.c, other.c))
}

func (n Node) IsNull() bool {
	return bool(C.ts_node_is_null(n.c))
}

func (n Node) IsNamed() bool {
	return bool(C.ts_node_is_named(n.c))
}

func (n Node) IsMissing() bool {
	return bool(C.ts_node_is_missing(n.c))
}

func (n Node) HasChanges() bool {
	return bool(C.ts_node_has_changes(n.c))
}

func (n Node) HasError() bool {
	return bool(C.ts_node_has_error(n.c))
}

func (n Node) Parent() *Node {
	nn := C.ts_node_parent(n.c)
	if nn.id == nil {
		return nil
	}
	return &Node{nn, n.t}
}

func (n Node) Child(idx int) *Node {
	nn := C.ts_node_child(n.c, C.uint32_t(idx))
	if nn.id == nil {
		return nil
	}
	return &Node{nn, n.t}
}

func (n Node) NamedChild(idx int) *Node {
	nn := C.ts_node_named_child(n.c, C.uint32_t(idx))
	if nn.id == nil {
		return nil
	}
	return &Node{nn, n.t}
}

func (n Node) ChildCount() uint32 {
	return uint32(C.ts_node_child_count(n.c))
}

func (n Node) NamedChildCount() uint32 {
	return uint32(C.ts_node_named_child_count(n.c))
}

func (n Node) NextSibling() *Node {
	nn := C.ts_node_next_sibling(n.c)
	if nn.id == nil {
		return nil
	}
	return &Node{nn, n.t}
}

func (n Node) NextNamedSibling() *Node {
	nn := C.ts_node_next_named_sibling(n.c)
	if nn.id == nil {
		return nil
	}
	return &Node{nn, n.t}
}

func (n Node) PrevSibling() *Node {
	nn := C.ts_node_prev_sibling(n.c)
	if nn.id == nil {
		return nil
	}
	return &Node{nn, n.t}
}

func (n Node) PrevNamedSibling() *Node {
	nn := C.ts_node_prev_named_sibling(n.c)
	if nn.id == nil {
		return nil
	}
	return &Node{nn, n.t}
}
