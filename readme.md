# Pipex

### Introduction

Pipex is a project designed to help you understand and implement the pipe mechanism in UNIX systems. Pipes enable the output of one command to be used as the input of another. This project mimics the shell command:

```
< file1 cmd1 | cmd2 > file2
```

## Features

- Handles two commands connected by a pipe.
- Opens an input file and redirects its content as input to the first command.
- Redirects the output of the second command to an output file.
- Includes error handling for common issues like file access or command execution failures.
- Implements dynamic path resolution for commands using the system's `PATH` variable.

## How It Works

The program takes the following arguments:

- `file1` - Input file.
- `cmd1` - First shell command (with parameters).
- `cmd2` - Second shell command (with parameters).
- `file2` - Output file.

### The Execution Flow

1. The program opens `file1` and uses it as the input for `cmd1`.
2. The output of `cmd1` is piped as input to `cmd2`.
3. The output of `cmd2` is written to `file2`.

#### Example
Command:
```
./pipex infile "ls -l" "wc -l" outfile
```

Equivalent to:
```
< infile ls -l | wc -l > outfile
```

### How to Build and Run
#### Build
To compile the project, ensure that you have make and a C compiler installed. Then, run:
```
make
```
This will create the pipex executable.

#### Run
The program can be executed using the following syntax:
```
./pipex file1 "cmd1" "cmd2" file2
```

### Example Usage

1. **Basic Example**:
```
./pipex input.txt "cat" "wc -l" output.txt
```
This command counts the number of lines in `input.txt` and saves the result to output.txt.

2. **Custom Commands:**:
```
./pipex `data.txt` "grep hello" "sort" result.txt
```
Filters lines containing "hello" in `data.txt`, sorts them, and saves the result to result.txt.

## Files and Structure

- **`pipex.c`**: Main program logic and process creation.
- **`run_commands.c`**: Handles command execution and path resolution.
- **`utils.c`**: Utility functions for cleanup and initialization.
- **`pipex.h`**: Header file with function declarations and includes.

## What I Learned

- **UNIX System Calls**: Gained experience with `pipe`, `fork`, `dup2`, and `execve`.
- **Process Management**: Learned to manage multiple processes and synchronize them with `waitpid`.
- **Error Handling**: Improved skills in detecting and handling runtime errors effectively.
- **Dynamic Memory Management**: Ensured no memory leaks using proper cleanup practices.
- **Makefiles**: Enhanced knowledge of creating modular and efficient `Makefile` rules.

## Cleaning Up

To remove compiled files, use:
```
make clean
```

To remove everything (including the executable):
```
make fclean
```

To rebuild from scratch:
```
make re
```
