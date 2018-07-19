package sitter

func FuncName(content []byte, n *Node) string {
	if n == nil {
		return ""
	}

	if n.Type() != "function" {
		return ""
	}

	c := n.NamedChild(0)
	if c == nil {
		return ""
	}

	return string(content[c.StartByte():c.EndByte()])
}
