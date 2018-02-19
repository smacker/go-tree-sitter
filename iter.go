package sitter

import (
	"io"
)

type IterMode int

const (
	DFSMode IterMode = iota
	BFSMode
)

type iterator struct {
	named bool
	mode  IterMode

	nodesToVisit []*Node
}

func NewIterator(n *Node, mode IterMode) *iterator {
	return &iterator{
		named:        true,
		mode:         mode,
		nodesToVisit: []*Node{n},
	}
}

func (iter *iterator) Next() (*Node, error) {
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

func (iter *iterator) ForEach(fn func(*Node) error) error {
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
