#/bin/bash

set -e

if [ -d tree-sitter ]; then
    (cd tree-sitter; git pull origin master)
else
    git clone https://github.com/tree-sitter/tree-sitter.git
fi;

(cd tree-sitter; git checkout 16376c43f5cc75bbc5297e6d5716bd94d55ccc05)

if [ -d javascript/tree-sitter-javascript ]; then
    (cd javascript/tree-sitter-javascript; git pull origin master)
else
    git clone https://github.com/tree-sitter/tree-sitter-javascript.git javascript/tree-sitter-javascript
fi;

(cd javascript/tree-sitter-javascript; git checkout 740716dfb0dd31e57c5d7e2b2ee8d49ec082f16c)

if [ -e ./tree-sitter/out/Release ]; then
  rm -rf ./tree-sitter/out/Release
fi;

cd tree-sitter
script/configure
make runtime
cd ..

if [ -e ./tree-sitter/out/Release/obj.target ]; then
  mv ./tree-sitter/out/Release/obj.target/* ./tree-sitter/out/Release
fi;

go run example/main.go
