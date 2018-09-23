#/bin/bash

set -e

if [ -e ./vendor/tree-sitter/out/Release ]; then
  rm -rf ./vendor/tree-sitter/out/Release
fi;

(
    cd vendor/tree-sitter
    script/configure
    make runtime
)

if [ -e ./vendor/tree-sitter/out/Release/obj.target ]; then
  mv ./vendor/tree-sitter/out/Release/obj.target/* ./vendor/tree-sitter/out/Release
fi;

go run example/main.go
