# ALX Simple Shell Project (hsh)

## Overview
Welcome to the ALX collaboration project on Shell! Our simple shell, named **hsh**, is a basic UNIX command language interpreter. It is written in C, utilizing shell scripting, and adheres to the Betty linter coding style.

## Description
The hsh shell operates by reading commands from either a file or standard input and executing them. Here's an overview of its functionality:

1. **User Interaction:**
   - hsh prompts the user for commands.
   - It waits for the user to input a command.

2. **Command Execution:**
   - Upon receiving a command, hsh creates a child process to handle the execution.
   - The child process checks and validates the given command.

3. **Command Replacement:**
   - The child process is replaced by the executed command, which may include arguments.

4. **Return to Parent Process:**
   - After command execution, the program returns to the parent process.

5. **Prompt Printing:**
   - The parent process prints the prompt, indicating that the program is ready for a new command.

6. **Built-in Commands and Aliases:**
   - hsh checks for built-in commands.
   - It also looks for aliases in the system's path.

7. **Local Executables:**
   - hsh recognizes and executes local executable programs.

8. **Non-Interactive Mode:**
   - hsh is designed to work in non-interactive modes as well.

## Contributors
This project was made possible through the collaboration of various contributors. Special thanks to:

- **Kryuell**
- **MounimNadir**

## Usage
To use hsh, simply run the executable and start entering commands when prompted.

```bash
$ ./hsh
hsh$ ls -l
... (output of 'ls -l' command)
hsh$ echo "Hello, World!"
Hello, World!
hsh$ exit
$
