package sitter

import "io"

type IterMode int

const (
	DFSMode IterMode = iota
	BFSMode
)

// Iterator for a tree of nodes
type Iterator struct {
	named bool
	mode  IterMode

	nodesToVisit []*Node
}

// NewIterator takes a node and mode (DFS/BFS) and returns iterator over named children of the node
func NewIterator(n *Node, mode IterMode) *Iterator {
	return &Iterator{
		named:        true,
		mode:         mode,
		nodesToVisit: []*Node{n},
	}
}

func (iter *Iterator) Next() (*Node, error) {
	if len(iter.nodesToVisit) == 0 {
		return nil, io.EOF
	}

	var n *Node
	n, iter.nodesToVisit = iter.nodesToVisit[0], iter.nodesToVisit[1:]
	switch iter.mode {
	case DFSMode:
		for i := 0; i < int(n.NamedChildCount()); i++ {
			iter.nodesToVisit = append(iter.nodesToVisit, n.NamedChild(i))
		}
	case BFSMode:
		for i := 0; i < int(n.NamedChildCount()); i++ {
			iter.nodesToVisit = append([]*Node{n.NamedChild(i)}, iter.nodesToVisit...)
		}
	default:
		panic("not implemented")
	}
	return n, nil
}

func (iter *Iterator) ForEach(fn func(*Node) error) error {
	for {
		n, err := iter.Next()
		if err != nil {
			return err
		}
		err = fn(n)
		if err != nil {
			return err
		}
	}
}
