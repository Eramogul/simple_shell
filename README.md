# Simple Shell

## Description

This project implements a simple Unix command line interpreter. It displays a prompt, waits for user input, and executes commands as specified. 

## Features

- Display a prompt (`#cisfun$ `).
- Wait for user input, execute the command, and then re-prompt.
- Handle simple commands without arguments.
- Handle errors and special conditions like `Ctrl+D` to exit.
- Uses `execve` as the core system call.

## Usage

Compile with:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

