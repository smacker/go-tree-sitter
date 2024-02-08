# Grammar Version Checker

This Go program automates the process of checking and updating grammar versions for various programming languages. It targets specific grammars defined in a JSON configuration file and supports operations like checking for updates and performing updates.

## Features

- **Check for Updates**: Scan through defined grammars and check if there are new versions available.
- **Update Grammar**: Update a specific grammar to its latest version.
- **Update All**: Batch update all grammars to their latest versions.

## Prerequisites

- Go installed on your machine.
- Git installed and accessible from your command line.

## Configuration

The program relies on a JSON file (`_automation/grammars.json`) for the list of grammars to manage. Each grammar should specify its `language`, `url`, `files`, `reference` (tag or branch), and `revision` (commit hash).

Example structure of `grammars.json`:

```json
[
  {
    "language": "Go",
    "url": "https://github.com/tree-sitter/tree-sitter-go",
    "files": ["parser.c", "scanner.cc"],
    "reference": "v0.19.0",
    "revision": "abcd1234"
  }
]
```
## Usage 

### To Check for Updates

```bash
go run ./_automation/main.go check-updates
```

### To update a specific grammar
```bash
go run ./_automation/main.go update <language> [--force]
```

### To update all grammars
```bash
go run ./_automation/main.go update-all
```