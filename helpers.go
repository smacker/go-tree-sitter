package sitter

func NodeValue(content []byte, n *Node) string {
	if n == nil {
		return ""
	}

	c := n.NamedChild(0)
	if c == nil {
		return ""
	}

	return string(content[c.StartByte():c.EndByte()])
}
