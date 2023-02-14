#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


/* Define MAX_COMMAND_LENGTH and MAX_BUFFER_LENGTH */
#define MAX_COMMAND_LENGTH 128
#define MAX_BUFFER_LENGTH 1024

/*Function prototypes*/

int execute_command(char** args);
int execute_cd(char** args);
int execute_setenv(char** args);
int execute_unsetenv(char** args);
int execute_alias(char** args);
int execute_file(char *filename);
void print_prompt();
char* getline();
char** parse_command_line(char *command_line);

#endif