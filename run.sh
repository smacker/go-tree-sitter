#/bin/bash

set -e

git clone https://github.com/tree-sitter/tree-sitter.git
git clone https://github.com/tree-sitter/tree-sitter-javascript.git
cd tree-sitter
script/configure
make
cd ..
go run example/main.go
