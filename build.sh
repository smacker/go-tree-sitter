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

# grammars
langs="python ruby"
for lang in ${langs}
do
    cp -R ./vendor/tree-sitter-$lang/src/parser.c \
        ./vendor/tree-sitter-$lang/src/scanner.cc \
        ./vendor/tree-sitter-$lang/src/tree_sitter \
        ./$lang
done

go run example/main.go
