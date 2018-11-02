all: tree-sitter grammars

tsprefix := vendor/tree-sitter
tree_sitter_c := get_changed_ranges.c \
	language.c \
	lexer.c \
	node.c \
	parser.c \
	stack.c \
	subtree.c \
	tree_cursor.c \
	tree.c \
	utf16.c

tree_sitter_files = $(addprefix $(tsprefix)/src/runtime/,$(addsuffix .o, $(basename $(tree_sitter_c))))

.PHONY: tree-sitter
tree-sitter: pre_sitter $(tree_sitter_files) $(tsprefix)/externals/utf8proc/utf8proc.o $(tsprefix)/tree_sitter.a

$(tree_sitter_files): %.o : %.c
	gcc -I $(tsprefix)/include -I $(tsprefix)/externals/utf8proc -I $(tsprefix)/src -c $< -o $@

$(tsprefix)/externals/utf8proc/utf8proc.o:
	gcc -I $(tsprefix)/externals/utf8proc -c $(tsprefix)/externals/utf8proc/utf8proc.c -o $(tsprefix)/externals/utf8proc/utf8proc.o

$(tsprefix)/tree_sitter.a:
	ar rcs $(tsprefix)/tree_sitter.a $(tree_sitter_files) $(tsprefix)/externals/utf8proc/utf8proc.o

gprefix := vendor/tree-sitter-
parsers := $(patsubst %src/parser.c,%parser.o,$(wildcard vendor/tree-sitter-*/src/parser.c))
scanners_c := $(patsubst %src/scanner.c,%scanner.o,$(wildcard vendor/tree-sitter-*/src/scanner.c))
scanners_cc := $(patsubst %src/scanner.cc,%scanner.o,$(wildcard vendor/tree-sitter-*/src/scanner.cc))

.PHONY: grammars
grammars: pre_grammars $(parsers) $(scanners_c) $(scanners_cc)

$(parsers): $(gprefix)%/parser.o : $(gprefix)%/src/parser.c
	gcc -I$(gprefix)$*/src -c $< -o $@

$(scanners_c): $(gprefix)%/scanner.o : $(gprefix)%/src/scanner.c
	gcc -std=c99 -I$(gprefix)$*/src -c $< -o $@

$(scanners_cc): $(gprefix)%/scanner.o : $(gprefix)%/src/scanner.cc
	g++ -I$(gprefix)$*/src -c $< -o $@

clean:
	rm -rf vendor/tree-sitter/tree_sitter.a
	rm -rf $(wildcard vendor/tree-sitter/src/runtime/*.o)
	rm -rf $(wildcard vendor/tree-sitter/src/externals/utf8proc/*.o)
	rm -rf $(wildcard vendor/tree-sitter-*/parser.o)
	rm -rf $(wildcard vendor/tree-sitter-*/scanner.o)

.PHONY: pre_sitter
pre_sitter:
	@echo ">>> compiling tree-sitter";

.PHONY: pre_grammars
pre_grammars:
	@echo ">>> compiling grammars";
