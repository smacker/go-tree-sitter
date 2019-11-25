#!/bin/bash

# Script to update tree-sitter and grammars

set -e

function download_sitter() {
    rm -rf vendor;
    git clone -b $1 https://github.com/tree-sitter/tree-sitter.git vendor/tree-sitter
    for file in ./vendor/tree-sitter/lib/include/tree_sitter/*.h; do
        cp "$file" ./
    done
    for file in ./vendor/tree-sitter/lib/src/*.c; do
        cp "$file" ./
    done
    for file in ./vendor/tree-sitter/lib/src/*.h; do
        cp "$file" ./
    done
    for file in ./vendor/tree-sitter/lib/src/unicode/*.h; do
        cp "$file" ./
    done
    rm -rf vendor

    rm ./lib.c
    sed -i 's/"tree_sitter\//"/g' ./*.c
    sed -i 's/"tree_sitter\//"/g' ./*.h
    sed -i 's/"unicode\//"/g' ./*.h
    sed -i 's/"api\.h"/"api\.h"\n#include "unicode\.h"/g' ./*.h
}

function download_grammar() {
    lang=$1; shift
    version=$1; shift
    files=$@
    target=$lang
    if [ "$lang" == "go" ]; then
        target="golang"
    fi

    echo "downloading $lang $version"
    curl -s -f -S "https://raw.githubusercontent.com/tree-sitter/tree-sitter-$lang/$version/src/tree_sitter/parser.h" -o "$target/parser.h"
    for file in $files; do
        curl -s -f -S "https://raw.githubusercontent.com/tree-sitter/tree-sitter-$lang/$version/src/$file" -o "$target/$file"
        sed -i 's/<tree_sitter\/parser\.h>/"parser\.h"/g' "$target/$file"
    done
}

download_sitter 0.15.13

download_grammar bash v0.16.0 parser.c scanner.cc
download_grammar c v0.15.2 parser.c
download_grammar cpp v0.15.0 parser.c scanner.cc
download_grammar go v0.15.0 parser.c
download_grammar java v0.13.0 parser.c
download_grammar javascript v0.15.1 parser.c scanner.c
download_grammar php v0.13.1 parser.c scanner.cc
download_grammar python v0.15.0 parser.c scanner.cc
download_grammar ruby v0.15.2 parser.c scanner.cc
download_grammar rust v0.15.1 parser.c scanner.c

# typescript is special as it contains 2 different grammars
function download_typescript() {
    version=$1; shift
    langs="typescript tsx"
    files="parser.c scanner.c"

    echo "downloading typescript $version"
    for lang in $langs; do
        curl -s -f -S "https://raw.githubusercontent.com/tree-sitter/tree-sitter-typescript/$version/common/scanner.h" -o "typescript/$lang/scanner.h"
        curl -s -f -S "https://raw.githubusercontent.com/tree-sitter/tree-sitter-typescript/$version/$lang/src/tree_sitter/parser.h" -o "typescript/$lang/parser.h"
        for file in $files; do
            curl -s -f -S "https://raw.githubusercontent.com/tree-sitter/tree-sitter-typescript/$version/$lang/src/$file" -o "typescript/$lang/$file"
            sed -i 's/"\.\.\/\.\.\/common\/scanner\.h"/"scanner\.h"/g' "typescript/$lang/$file"
            sed -i 's/<tree_sitter\/parser\.h>/"parser\.h"/g' "typescript/$lang/$file"
        done
        sed -i 's/<tree_sitter\/parser\.h>/"parser\.h"/g' "typescript/$lang/scanner.h"
    done
}

download_typescript v0.15.1
