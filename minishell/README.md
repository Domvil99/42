_This project has been created as part of the 42 curriculum by domvil._

# Minishell

## Description
Minishell is a simple shell implementation written in C. The project supports command execution, environment management, pipes, redirections, heredoc, variable expansion, and basic built-in commands.

**Status**: ✅ **Mandatory 100% Complete**

## Instructions
### Compile
```bash
cd 42/C/minishell
make clean && make
```

### Run
```bash
./minishell
```

### Usage
- Type commands and press Enter.
- Use `Ctrl+C` to cancel the current line and show a new prompt.
- Use `Ctrl+D` to exit the shell.
- Use `exit` to quit.

## Features

### Mandatory ✅
- **Interactive prompt** with history
- **Built-in Commands**: `echo` (with `-n`), `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- **Environment variable expansion**: `$VAR`, `$?` (last exit status)
- **Redirections**: `<` (input), `>` (output), `>>` (append), `<<` (heredoc)
- **Pipes**: Connect commands with `|`
- **Quote handling**: Single quotes (no expansion), double quotes (with `$` expansion)
- **Signal handling**:
  - `Ctrl+C`: New prompt on new line
  - `Ctrl+D`: Exit shell
  - `Ctrl+\`: Ignore signal


## Validation

### Test Results
```
✓ pipes
✓ exit
✓ core functionality
```

### Compilation
- Clean compilation with `-Wall -Wextra -Werror`
- Minimal memory leaks (readline overhead excluded)
- Valgrind validated

## Resources
- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [readline Library](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [Linux Man Pages - Process Management](https://man7.org/linux/man-pages/)
- [POSIX Shell Specification](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)

## AI Usage
- **Code Structure & Architecture**: Planning shell structure and pipeline design
- **Signal Handling**: Proper signal handler implementation
- **Variable Expansion**: Dynamic string building and environment management
- **Memory Management**: Leak identification and cleanup strategies
- **Validation**: Testing strategies and edge case handling

All code changes were reviewed and validated manually against the subject specification.

## Implementation Notes

### Architecture
1. **Parsing**: Tokenization while respecting quotes and operators
2. **Expansion**: Environment variables
3. **Execution**: Router for builtins, external commands, pipes, and logical chains
4. **Cleanup**: Proper memory deallocation and file descriptor closure

### Key Technical Decisions
- Single global variable (`g_signal_received`) for signal management (per subject)
- Dynamic memory allocation using libft for safety
- Proper fork/execve/waitpid flow for external command execution
- Careful file descriptor management with dup2

### Known Limitations
- Norminette: Some style issues remain (function length > 25 lines, many functions per file)
- Readline leaks: Expected, excluded from leak count per subject

---

**Last Updated**: May 18, 2026  
**Status**: Ready for evaluation (mandatory 100%)

