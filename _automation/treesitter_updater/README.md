# Tree Sitter Updater

This Go program automates the process of downloading, extracting, and processing the specified version of the [Tree Sitter library](https://github.com/tree-sitter/tree-sitter). It's designed to simplify the updating of the upstream Tree Sitter library for use in this project.


## Usage

If you want to change the version of the treesitter library that is retrieved, update the `sitterVersion` variable in `main.go`.

Note, you must run this script from within the `_automation/treesitter_updater` directory because it makes an assumption that the final destination for the .C and .H files is 2 directories up from it's current directory.

```bash
cd _automation/treesitter_updater
go run main.go
```

The success / failure will be printed to stdout, as well as a list of (1) new files and (2) replaced files.

## Constants

- `sitterVersion`: Specifies the version of Tree Sitter to download.
- `sitterURL`: The URL to the Tree Sitter source for the specified version.

