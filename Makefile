all: tree-sitter grammars

.PHONY: tree-sitter
tree-sitter: pre_sitter vendor/tree-sitter/out/Release/libruntime.a

vendor/tree-sitter/out/Release/libruntime.a:
	cd vendor/tree-sitter; \
	script/configure; \
	make runtime; \
	if [ -e ./out/Release/obj.target ]; then \
		mv ./out/Release/obj.target/* ./out/Release; \
	fi; \

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
	rm -rf vendor/tree-sitter/out/Release/libruntime.a
	rm -rf $(wildcard vendor/tree-sitter-*/parser.o)
	rm -rf $(wildcard vendor/tree-sitter-*/scanner.o)

.PHONY: pre_sitter
pre_sitter:
	@echo ">>> compiling tree-sitter";

.PHONY: pre_grammars
pre_grammars:
	@echo ">>> compiling grammars";
