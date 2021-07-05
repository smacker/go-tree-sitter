#!/bin/bash

# Script to update tree-sitter and grammars

set -e

sitter_version=v0.20.0
grammars=(
    "bash;v0.16.1;parser.c;scanner.cc"
    "c-sharp;v0.16.1;parser.c;scanner.c"
    "c;v0.16.0;parser.c"
    "cpp;v0.16.0;parser.c;scanner.cc"
    "go;v0.16.0;parser.c"
    "java;v0.16.0;parser.c"
    "javascript;v0.16.0;parser.c;scanner.c"
    "php;v0.16.1;parser.c;scanner.cc"
    "python;v0.16.1;parser.c;scanner.cc"
    "ruby;v0.16.1;parser.c;scanner.cc"
    "rust;v0.16.0;parser.c;scanner.c"
    "typescript;v0.16.1"
    "elm;v2.7.7;parser.c;scanner.cc"
    "lua;v1.6.0;parser.c;scanner.cc"
    "ocaml;v0.15.0;parser.c;scanner.cc"
    "css;v0.16.0;parser.c;scanner.c"
    "html;v0.16.0;parser.c;scanner.cc;tag.h"
    "scala;v0.13.0;parser.c;scanner.c"
    "yaml;v0.1.0;parser.c;scanner.cc"
    "toml;v0.2.0;parser.c;scanner.c"
    "svelte;v0.6.0;parser.c;scanner.cc;tag.hh"
)

declare -A repositories
repositories=(
    ["elm"]="Razzeee/tree-sitter-elm"
    ["lua"]="Azganoth/tree-sitter-lua"
    ["yaml"]="ikatyang/tree-sitter-yaml"
    ["toml"]="ikatyang/tree-sitter-toml"
    ["svelte"]="Himujjal/tree-sitter-svelte"
)


function download_sitter() {
    rm -rf vendor
    git clone -b $1 https://github.com/tree-sitter/tree-sitter.git vendor

    sed -i.bak 's/"tree_sitter\//"/g' vendor/lib/src/*.c vendor/lib/src/*.h
    sed -i.bak 's/"unicode\//"/g' vendor/lib/src/unicode/*.h vendor/lib/src/*.h

    cp vendor/lib/include/tree_sitter/*.h ./
    cp vendor/lib/src/*.c ./
    cp vendor/lib/src/*.h ./
    cp vendor/lib/src/unicode/*.h ./
    rm -rf vendor

    # avoid "duplicate symbols" errors as go compiles all c files separately
    rm ./lib.c
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

    repository=${repositories[$lang]}
    if [ "$repository" == "" ]; then
        repository="tree-sitter/tree-sitter-$lang"
    fi

    url="https://raw.githubusercontent.com/$repository"
    mkdir -p "$target"

    echo "downloading $lang $version"
    curl -s -f -S "$url/$version/src/tree_sitter/parser.h" -o "$target/parser.h"
    for file in $files; do
        curl -s -f -S "$url/$version/src/$file" -o "$target/$file"
        sed -i.bak 's/<tree_sitter\/parser\.h>/"parser\.h"/g' "$target/$file"
        rm "$target/$file.bak"
    done
}

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
            sed -i.bak 's/"\.\.\/\.\.\/common\/scanner\.h"/"scanner\.h"/g' "typescript/$lang/$file"
            sed -i.bak 's/<tree_sitter\/parser\.h>/"parser\.h"/g' "typescript/$lang/$file"
        done
        sed -i.bak 's/<tree_sitter\/parser\.h>/"parser\.h"/g' "typescript/$lang/scanner.h"
        rm typescript/$lang/*.bak
    done
}

function download() {
    download_sitter $sitter_version

    for grammar in ${grammars[@]}; do
        if [[ "$grammar" == typescript* ]]; then
            download_typescript `echo $grammar | cut -d';' -f2`
        else
            download_grammar `echo $grammar | tr ';' ' '`
        fi
    done
}

function print_grammar_version() {
    lang=$1
    version=$2
    repository=${repositories[$lang]}
    if [ "$repository" == "" ]; then
        repository="tree-sitter/tree-sitter-$lang"
    fi
    remote_version=`git ls-remote --tags --refs --sort='-v:refname' "https://github.com/$repository.git" v\* | head -n 1 | cut -f2 | cut -d'/' -f3`
    outdated=""
    if [ "$version" != "$remote_version" ]; then
        outdated="outdated"
    fi

    echo -e "$lang\t\tvendored: $version\tremote: $remote_version\t$outdated"
}

function check-updates() {
    remote_version=`git ls-remote --tags --refs --sort='-v:refname' "https://github.com/tree-sitter/tree-sitter.git" | head -n 1 | cut -f2 | cut -d'/' -f3`
    outdated=""
    if [ "$sitter_version" != "$remote_version" ]; then
        outdated="outdated"
    fi
    echo -e "tree-sitter\tvendored: $sitter_version\tremote: $remote_version\t$outdated"

    for grammar in ${grammars[@]}; do
        print_grammar_version `echo $grammar | tr ';' ' '`
    done
}

function help() {
    echo "this script supports 2 subcommands:"
    echo "* check-updates - compares vendored versions with remote"
    echo "* download - re-downloads vendored files"
}

case $1 in
check-updates) check-updates
;;
download) download
;;
*) help
;;
esac
