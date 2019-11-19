#!/bin/bash

# Script to update tree-sitter and grammars

set -e

function download_sitter() {
    rm -rf vendor
    git clone -b $1 https://github.com/tree-sitter/tree-sitter.git vendor/tree-sitter
}

function download_grammar() {
    lang=$1; shift
    version=$1; shift
    files=$@
    target=$lang
    if [ "$lang" == "go" ]; then
        target="golang"
    fi
    if [ "$lang" == "c-sharp" ]; then
        target="csharp"
    fi

    echo "downloading $lang $version"
    mkdir -p "$target/tree_sitter"
    curl -s -f -S "https://raw.githubusercontent.com/tree-sitter/tree-sitter-$lang/$version/src/tree_sitter/parser.h" -o "$target/tree_sitter/parser.h"
    for file in $files; do
        curl -s -f -S "https://raw.githubusercontent.com/tree-sitter/tree-sitter-$lang/$version/src/$file" -o "$target/$file"
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
download_grammar c-sharp master parser.c
