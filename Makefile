# directory to download dependencies in
vendor_dir = vendor

# sha of the commit in tree-sitter (it doesn't have tags)
tree_sitter_sha = 3faaec33175c9ff04391f60b28d0d1a1910f193d

# list of versions per grammar
bash_version = v0.13.6
go_version = v0.13.3
java_version = v0.13.0
javascript_version = v0.13.8
python_version = v0.13.4
ruby_version = v0.13.11

all: | $(vendor_dir) tree-sitter grammars

$(vendor_dir):
	mkdir -p $@

# tree-sitter rules

tree_sitter_dir = $(vendor_dir)/tree-sitter
tree_sitter_lib = $(vendor_dir)/tree_sitter.a

# list of compiled files from C for tree-sitter
targets = $(addprefix $(tree_sitter_dir)/src/runtime/,\
	get_changed_ranges.o \
	language.o \
	lexer.o \
	node.o \
	parser.o \
	stack.o \
	subtree.o \
	tree_cursor.o \
	tree.o \
	utf16.o \
)

utf8proc_target = $(tree_sitter_dir)/externals/utf8proc/utf8proc.o

.PHONY: tree-sitter
tree-sitter: | $(tree_sitter_dir) $(tree_sitter_lib)

$(tree_sitter_dir):
	@git clone https://github.com/tree-sitter/tree-sitter.git $@; \
	cd $@; \
	git checkout $(tree_sitter_sha); \
	git submodule init externals/utf8proc; \
	git submodule update externals/utf8proc;

$(tree_sitter_lib): $(targets) $(utf8proc_target)
	ar rcs $@ $(targets) $(utf8proc_target)

$(targets): %.o : %.c
	gcc -I $(tree_sitter_dir)/include -I $(tree_sitter_dir)/externals/utf8proc -I $(tree_sitter_dir)/src -c $< -o $@

$(utf8proc_target): %.o : %.c
	gcc -I $(@D) -c $< -o $@

# grammars rules

# list of compiled files from C for all grammars
targets_c = $(addprefix $(vendor_dir)/,\
	bash/parser.o \
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
	python/scanner.o \
	ruby/scanner.o \
)

targets_dirs = $(sort $(dir $(targets_c) $(targets_cc)))

.PHONY: grammars
grammars: $(targets_dirs) $(targets_c) $(targets_cc)

$(targets_dirs):
	mkdir -p $@

$(targets_c): %.o: %.c
	gcc -std=c99 -I vendor/tree-sitter/include -c $< -o $@

$(targets_cc): %.o: %.cc
	g++ -I vendor/tree-sitter/include -c $< -o $@

$(patsubst %.o,%.c,$(targets_c)) $(patsubst %.o,%.cc,$(targets_cc)):
	curl -s "https://raw.githubusercontent.com/tree-sitter/tree-sitter-$(subst vendor/,,$(@D))/$($(subst vendor/,,$(@D))_version)/src/$(@F)" -o $@

clean:
	rm -rf $(vendor_dir)
