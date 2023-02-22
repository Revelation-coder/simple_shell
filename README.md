--------------------------C Simple Shell--------------------------------------------------------------------------------------


--------------------------PROJECT DETAILS-------------------------------------------------------------------------------------


Welcome to the "C Simple Shell"
This program is a simple shell that can be compiled and launched from the command line.

How to Compile
---------------
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh


Syntax
-----
When using this shell, the syntax for running any command follows the familiar syntax when running a command in any other shell.


Builtin Commands
-----
This shell supports a variety of commands:

"alias" - create or list an alias

"cd" - change directory

"env" - list the current environment variables

"exit" - exit the shell

"history" - display the command history for the current shell session

"setenv" - sets an environment variable

"unsetenv" - unsets an environment variable

help <builtin command>

### Compilation
-----
### Files
-----
Brief description of every file in this repository. Subject to change.

|--------- File Name-------------------| |--------------------------Description--------------------------------------------- |

| AUTHORS                              | Text file containing the contributing authors                                       |
| builtin1.c                           | Builtin commands source code #1 |
| builtin.c                            | Builtin commands source code #2 |
| errors.c                             | Error message handling source code |
| errors1.c                            | second error msg handli source code |
| lists.c                              | Link lists source code |
| lists1.c                             | linked lists functions source code |
| simple_shell_manual_page             | Manual page for our simple shell program |
| memory.c                             | Memory handling source code |
| README.md                            | This file that you are reading |
| main.c                               | Primary shell source code |
| shell.h                              | Shell header file |
| getinfo.c                            | Helper functions used in our implementation of shell #1 |
| parser.c                             | Helper functions used in our implementation of shell #2 |
| getenv.c                             | Get environment  functions used in our implementation of shell #3 |
| history.c                            | History functions used in our implementation of shell #4 |
| string.c                             | String function source code #1 |
| string1.c                            | String function source code #2 |
| realloc.c                            | Memory reallocation  function source code #3 |
| tokenizer.c                          | tokenizer functions            |
| vars.c                               | shell variables  

### Authors

Revelation Mudoti<captainrevelation@gmail.com>
Herbert Kabagambe<Khabertzion11@gmail.com>
