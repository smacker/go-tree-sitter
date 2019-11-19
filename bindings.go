package sitter

//#cgo CFLAGS: -g -I${SRCDIR}/vendor/tree-sitter/lib/include
//#cgo CFLAGS: -g -I${SRCDIR}/vendor/tree-sitter/lib/src
//#include "vendor/tree-sitter/lib/src/lib.c"
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

	return &Node{ptr, &Tree{cTree, make(map[C.TSNode]*Node)}}
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
	newTree := &Tree{
		C.ts_parser_parse_string(p.c, cTree, input, C.uint32_t(len(content))),
		make(map[C.TSNode]*Node),
	}
	runtime.SetFinalizer(newTree, deleteTree)
	return newTree
}

// OperationLimit returns the duration in microseconds that parsing is allowed to take
func (p *Parser) OperationLimit() int {
	return int(C.ts_parser_timeout_micros(p.c))
}

// SetOperationLimit limits the maximum duration in microseconds that parsing should be allowed to take before halting
func (p *Parser) SetOperationLimit(limit int) {
	C.ts_parser_set_timeout_micros(p.c, C.uint64_t(limit))
}

// Reset causes the parser to parse from scratch on the next call to parse, instead of resuming
// so that it sees the changes to the beginning of the source code.
func (p *Parser) Reset() {
	C.ts_parser_reset(p.c)
}

// SetIncludedRanges sets text ranges of a file
func (p *Parser) SetIncludedRanges(ranges []Range) {
	cRanges := make([]C.TSRange, len(ranges))
	for i, r := range ranges {
		cRanges[i] = C.TSRange{
			start_point: C.TSPoint{
				row:    C.uint32_t(r.StartPoint.Row),
				column: C.uint32_t(r.StartPoint.Column),
			},
			end_point: C.TSPoint{
				row:    C.uint32_t(r.EndPoint.Row),
				column: C.uint32_t(r.EndPoint.Column),
			},
			start_byte: C.uint32_t(r.StartByte),
			end_byte:   C.uint32_t(r.EndByte),
		}
	}
	C.ts_parser_set_included_ranges(p.c, (*C.TSRange)(unsafe.Pointer(&cRanges[0])), C.uint(len(ranges)))
}

// Debug enables debug output to stderr
func (p *Parser) Debug() {
	logger := C.stderr_logger_new(true)
	C.ts_parser_set_logger(p.c, logger)
}

func deleteParser(p *Parser) {
	C.ts_parser_delete(p.c)
}

type Point struct {
	Row    uint32
	Column uint32
}

type Range struct {
	StartPoint Point
	EndPoint   Point
	StartByte  uint32
	EndByte    uint32
}

// Tree represents the syntax tree of an entire source code file
// Note: Tree instances are not thread safe;
// you must copy a tree if you want to use it on multiple threads simultaneously.
type Tree struct {
	c *C.TSTree
	// most probably better save node.id
	cache map[C.TSNode]*Node
}

// Copy returns a new copy of a tree
func (t *Tree) Copy() *Tree {
	newTree := &Tree{C.ts_tree_copy(t.c), make(map[C.TSNode]*Node)}
	runtime.SetFinalizer(newTree, deleteTree)
	return newTree
}

// RootNode returns root node of a tree
func (t *Tree) RootNode() *Node {
	ptr := C.ts_tree_root_node(t.c)
	return t.cachedNode(ptr)
}

func (t *Tree) cachedNode(ptr C.TSNode) *Node {
	if ptr.id == nil {
		return nil
	}

	if n, ok := t.cache[ptr]; ok {
		return n
	}

	n := &Node{ptr, t}
	t.cache[ptr] = n
	return n
}

func deleteTree(t *Tree) {
	t.cache = nil
	C.ts_tree_delete(t.c)
}

type EditInput struct {
	StartIndex  uint32
	OldEndIndex uint32
	NewEndIndex uint32
	StartPoint  Point
	OldEndPoint Point
	NewEndPoint Point
}

func (i EditInput) c() *C.TSInputEdit {
	return &C.TSInputEdit{
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
}

// Edit the syntax tree to keep it in sync with source code that has been edited.
func (t *Tree) Edit(i EditInput) {
	C.ts_tree_edit(t.c, i.c())
}

// Language defines how to parse a particular programming language
type Language struct {
	ptr unsafe.Pointer
}

// NewLanguage creates new Language from c pointer
func NewLanguage(ptr unsafe.Pointer) *Language {
	return &Language{ptr}
}

// SymbolName returns a node type string for the given Symbol.
func (l *Language) SymbolName(s Symbol) string {
	return C.GoString(C.ts_language_symbol_name((*C.TSLanguage)(l.ptr), s))
}

// SymbolType returns named, anonymous, or a hidden type for a Symbol.
func (l *Language) SymbolType(s Symbol) SymbolType {
	return SymbolType(C.ts_language_symbol_type((*C.TSLanguage)(l.ptr), s))
}

// SymbolCount returns the number of distinct field names in the language.
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

// StartByte returns the node's start byte.
func (n Node) StartByte() uint32 {
	return uint32(C.ts_node_start_byte(n.c))
}

// EndByte returns the node's end byte.
func (n Node) EndByte() uint32 {
	return uint32(C.ts_node_end_byte(n.c))
}

// StartPoint returns the node's start position in terms of rows and columns.
func (n Node) StartPoint() Point {
	p := C.ts_node_start_point(n.c)
	return Point{
		Row:    uint32(p.row),
		Column: uint32(p.column),
	}
}

// EndPoint returns the node's end position in terms of rows and columns.
func (n Node) EndPoint() Point {
	p := C.ts_node_end_point(n.c)
	return Point{
		Row:    uint32(p.row),
		Column: uint32(p.column),
	}
}

// Symbol returns the node's type as a Symbol.
func (n Node) Symbol() Symbol {
	return C.ts_node_symbol(n.c)
}

// Type returns the node's type as a string.
func (n Node) Type() string {
	return C.GoString(C.ts_node_type(n.c))
}

// String returns an S-expression representing the node as a string.
func (n Node) String() string {
	ptr := C.ts_node_string(n.c)
	defer C.free(unsafe.Pointer(ptr))
	return C.GoString(ptr)
}

// Equal checks if two nodes are identical.
func (n Node) Equal(other *Node) bool {
	return bool(C.ts_node_eq(n.c, other.c))
}

// IsNull checks if the node is null.
func (n Node) IsNull() bool {
	return bool(C.ts_node_is_null(n.c))
}

// IsNamed checks if the node is *named*.
// Named nodes correspond to named rules in the grammar,
// whereas *anonymous* nodes correspond to string literals in the grammar.
func (n Node) IsNamed() bool {
	return bool(C.ts_node_is_named(n.c))
}

// IsMissing checks if the node is *missing*.
// Missing nodes are inserted by the parser in order to recover from certain kinds of syntax errors.
func (n Node) IsMissing() bool {
	return bool(C.ts_node_is_missing(n.c))
}

// HasChanges checks if a syntax node has been edited.
func (n Node) HasChanges() bool {
	return bool(C.ts_node_has_changes(n.c))
}

// HasError check if the node is a syntax error or contains any syntax errors.
func (n Node) HasError() bool {
	return bool(C.ts_node_has_error(n.c))
}

// Parent returns the node's immediate parent.
func (n Node) Parent() *Node {
	nn := C.ts_node_parent(n.c)
	return n.t.cachedNode(nn)
}

// Child returns the node's child at the given index, where zero represents the first child.
func (n Node) Child(idx int) *Node {
	nn := C.ts_node_child(n.c, C.uint32_t(idx))
	return n.t.cachedNode(nn)
}

// NamedChild returns the node's *named* child at the given index.
func (n Node) NamedChild(idx int) *Node {
	nn := C.ts_node_named_child(n.c, C.uint32_t(idx))
	return n.t.cachedNode(nn)
}

// ChildCount returns the node's number of children.
func (n Node) ChildCount() uint32 {
	return uint32(C.ts_node_child_count(n.c))
}

// NamedChildCount returns the node's number of *named* children.
func (n Node) NamedChildCount() uint32 {
	return uint32(C.ts_node_named_child_count(n.c))
}

// ChildByFieldName returns the node's child with the given field name.
func (n Node) ChildByFieldName(name string) *Node {
	nn := C.ts_node_child_by_field_name(n.c, C.CString(name), C.uint32_t(len(name)))
	return n.t.cachedNode(nn)
}

// NextSibling returns the node's next sibling.
func (n Node) NextSibling() *Node {
	nn := C.ts_node_next_sibling(n.c)
	return n.t.cachedNode(nn)
}

// NextNamedSibling returns the node's next *named* sibling.
func (n Node) NextNamedSibling() *Node {
	nn := C.ts_node_next_named_sibling(n.c)
	return n.t.cachedNode(nn)
}

// PrevSibling returns the node's previous sibling.
func (n Node) PrevSibling() *Node {
	nn := C.ts_node_prev_sibling(n.c)
	return n.t.cachedNode(nn)
}

// PrevNamedSibling returns the node's previous *named* sibling.
func (n Node) PrevNamedSibling() *Node {
	nn := C.ts_node_prev_named_sibling(n.c)
	return n.t.cachedNode(nn)
}

// Edit the node to keep it in-sync with source code that has been edited.
func (n Node) Edit(i EditInput) {
	C.ts_node_edit(&n.c, i.c())
}
