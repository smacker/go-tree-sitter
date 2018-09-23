#/bin/bash

set -e

if [ -d tree-sitter ]; then
    (cd tree-sitter; git pull origin master)
else
    git clone https://github.com/tree-sitter/tree-sitter.git
fi;

(cd tree-sitter; git checkout 257522372f8ee6359d1c28943eb519bc33904367)

if [ -d javascript/tree-sitter-javascript ]; then
    (cd javascript/tree-sitter-javascript; git pull origin master)
else
    git clone https://github.com/tree-sitter/tree-sitter-javascript.git javascript/tree-sitter-javascript
fi;

(cd javascript/tree-sitter-javascript; git checkout 740716dfb0dd31e57c5d7e2b2ee8d49ec082f16c)

cd tree-sitter
script/configure
make runtime
cd ..
go run example/main.go
