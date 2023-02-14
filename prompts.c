#include "shell.h"

/**
 * @print_prompt(): function to prompt user
 * @char* getline(): custom getline function 
 * @char** parse_command_line(char *command_line):function to parse command
 * 
 *
 * Return: void,command_line and args
 */

void print_prompt()
{
	char cwd[MAX_BUFFER_LENGTH];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s > ", cwd);
	}
	else
		{
			perror("shell");
		}
}

char* getline()
{
	char *command_line = malloc(sizeof(char) * MAX_BUFFER_LENGTH);
	int i;
	char c;

	/* Read characters until a \n is found*/

for (i = 0; i < MAX_BUFFER_LENGTH - 1; i++)
	{
		c = getchar();
		[i] = c;

		if (c == EOF || c == '\n')
		{
			break;
		}
	}
		command_line[i] = '\0';
		return command_line;
}

char** parse_command_line(char *command_line)
{
	int buffer_size = MAX_COMMAND_LENGTH;
	int position = 0;
	char **args = malloc(sizeof(char*) * buffer_size);
	char *token;

	if (!args)
		{
			fprintf(stderr, "shell: allocation error\n");
			exit(EXIT_FAILURE);
		}
	/* Tokenize the command line */

	token = strtok(command_line, " \t\r\n\a");

	while (token != NULL)
		{
			args[position] = token;
			position++;

	/* Reallocate if necessary */

		if (position >= buffer_size)
			{
				buffer_size += MAX_COMMAND_LENGTH;
				args = realloc(args, sizeof(char*) * buffer_size);
			if (!args)
				{
					fprintf(stderr, "shell: allocation error\n");
					exit(EXIT_FAILURE);
				}
			}

	token = strtok(NULL, " \t\r\n\a");
	}

	args[position] = NULL;

	return args;
}