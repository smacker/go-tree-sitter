# directory to download dependencies in
vendor_dir = vendor

# tree-sitter runtime version
tree_sitter_version = 0.14.7

# list of versions per grammar
bash_version = v0.13.9
c_version = v0.13.13
cpp_version = v0.13.15
go_version = v0.13.3
java_version = v0.13.0
javascript_version = v0.13.10
python_version = v0.14.0
ruby_version = v0.13.14

all: | $(vendor_dir) tree-sitter grammars

$(vendor_dir):
	mkdir -p $@

# tree-sitter rules

tree_sitter_dir = $(vendor_dir)/tree-sitter
tree_sitter_lib = $(vendor_dir)/tree_sitter.a

.PHONY: tree-sitter
tree-sitter: | $(tree_sitter_dir) $(tree_sitter_lib)

$(tree_sitter_dir):
	@git clone -b $(tree_sitter_version) https://github.com/tree-sitter/tree-sitter.git $@; \
	cd $@; \
	git submodule init lib/utf8proc; \
	git submodule update lib/utf8proc;

$(tree_sitter_lib):
	gcc -c -O3 -std=c99 \
	-I $(tree_sitter_dir)/lib/src -I $(tree_sitter_dir)/lib/include -I $(tree_sitter_dir)/lib/utf8proc \
	-c $(tree_sitter_dir)/lib/src/lib.c -o tree_sitter.o
	ar rcs $@ tree_sitter.o
	rm tree_sitter.o

# grammars rules

# list of compiled files from C for all grammars
targets_c = $(addprefix $(vendor_dir)/,\
	bash/parser.o \
	c/parser.o \
	cpp/parser.o \
	go/parser.o \
	java/parser.o \
	javascript/scanner.o \
	javascript/parser.o \
	python/parser.o \
	ruby/parser.o \
)

# list of compiled files from C++ for all grammars
targets_cc = $(addprefix $(vendor_dir)/,\
	bash/scanner.o \
	cpp/scanner.o \
	python/scanner.o \
	ruby/scanner.o \
)

targets_dirs = $(sort $(dir $(targets_c) $(targets_cc)))

.PHONY: grammars
grammars: $(targets_dirs) $(targets_c) $(targets_cc)

$(targets_dirs):
	mkdir -p $@

$(targets_c): %.o: %.c
	gcc -std=c99 -I $(tree_sitter_dir)/lib/include -c $< -o $@

$(targets_cc): %.o: %.cc
	g++ -I $(tree_sitter_dir)/lib/include -c $< -o $@

$(patsubst %.o,%.c,$(targets_c)) $(patsubst %.o,%.cc,$(targets_cc)):
	curl -s "https://raw.githubusercontent.com/tree-sitter/tree-sitter-$(subst vendor/,,$(@D))/$($(subst vendor/,,$(@D))_version)/src/$(@F)" -o $@

clean:
	rm -rf $(vendor_dir)
