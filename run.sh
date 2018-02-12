#/bin/bash

set -e

git clone https://github.com/tree-sitter/tree-sitter.git
git clone https://github.com/tree-sitter/tree-sitter-javascript.git javascript/tree-sitter-javascript
cd tree-sitter
script/configure
make runtime
cd ..
go run example/main.go
