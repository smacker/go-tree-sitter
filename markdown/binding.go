package markdown

import (
	"context"

	sitter "github.com/smacker/go-tree-sitter"
	tree_sitter_markdown "github.com/smacker/go-tree-sitter/markdown/tree-sitter-markdown"
	tree_sitter_markdown_inline "github.com/smacker/go-tree-sitter/markdown/tree-sitter-markdown-inline"
)

type MarkdownTree struct {
	blockTree     *sitter.Tree
	inlineTrees   []*sitter.Tree
	inlineIndices map[uintptr]int
}

func (t *MarkdownTree) Edit(edit sitter.EditInput) {
	t.blockTree.Edit(edit)
	for _, tree := range t.inlineTrees {
		tree.Edit(edit)
	}
}

func (t *MarkdownTree) BlockTree() *sitter.Tree {
	return t.blockTree
}

func (t *MarkdownTree) InlineTree(parent *sitter.Node) *sitter.Tree {
	if parent == nil {
		return nil
	}

	index, ok := t.inlineIndices[parent.ID()]
	if ok {
		return t.inlineTrees[index]
	}

	return nil
}

func (t *MarkdownTree) InlineRootNode(parent *sitter.Node) *sitter.Node {
	tree := t.InlineTree(parent)
	if tree == nil {
		return nil
	}

	return tree.RootNode()
}

func (t *MarkdownTree) InlineTrees() []*sitter.Tree {
	return t.inlineTrees
}

func (t *MarkdownTree) Iter(f func(node *Node) bool) {
	root := t.blockTree.RootNode()
	t.iter(&Node{root, t.InlineRootNode(root)}, f)
}

func (t *MarkdownTree) iter(node *Node, f func(node *Node) bool) (goNext bool) {
	goNext = f(node)
	if !goNext {
		return goNext
	}

	childCount := node.NamedChildCount()
	for i := 0; i < int(childCount); i++ {
		child := node.NamedChild(i)

		goNext = t.iter(&Node{Node: child, Inline: t.InlineRootNode(child)}, f)
		if !goNext {
			return goNext
		}
	}

	return true
}

type Node struct {
	*sitter.Node
	Inline *sitter.Node
}

func ParseCtx(ctx context.Context, oldTree *MarkdownTree, content []byte) (*MarkdownTree, error) {
	p := sitter.NewParser()
	p.SetLanguage(tree_sitter_markdown.GetLanguage())

	var old *sitter.Tree
	if oldTree != nil {
		old = oldTree.blockTree
	}
	tree, err := p.ParseCtx(ctx, old, content)
	if err != nil {
		return nil, err
	}

	res := &MarkdownTree{
		blockTree:     tree,
		inlineTrees:   []*sitter.Tree{},
		inlineIndices: map[uintptr]int{},
	}

	p.SetLanguage(tree_sitter_markdown_inline.GetLanguage())

	q, err := sitter.NewQuery([]byte(`(inline) @inline`), tree_sitter_markdown.GetLanguage())
	if err != nil {
		return nil, err
	}

	qc := sitter.NewQueryCursor()
	qc.Exec(q, tree.RootNode())

	idx := int(0)
	for {
		match, ok := qc.NextMatch()
		if !ok {
			break
		}

		for _, capture := range match.Captures {
			r := capture.Node.Range()
			ranges := []sitter.Range{}
			for i := 0; i < int(capture.Node.NamedChildCount()); i++ {
				child := capture.Node.NamedChild(i)
				childRange := child.Range()
				ranges = append(ranges, sitter.Range{
					StartPoint: r.StartPoint,
					StartByte:  r.StartByte,
					EndPoint:   childRange.EndPoint,
					EndByte:    childRange.EndByte,
				})

				r.StartPoint = childRange.EndPoint
				r.StartByte = childRange.EndByte
			}

			ranges = append(ranges, r)
			p.SetIncludedRanges(ranges)
			var old *sitter.Tree
			if oldTree != nil && idx < len(oldTree.inlineTrees) {
				old = oldTree.inlineTrees[idx]
			}

			inlineTree, err := p.ParseCtx(ctx, old, content)
			if err != nil {
				return nil, err
			}

			res.inlineTrees = append(res.inlineTrees, inlineTree)
			res.inlineIndices[capture.Node.ID()] = idx
			idx++
		}
	}
	qc.Close()

	return res, nil
}
