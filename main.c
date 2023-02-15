#include "shell.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arguement  pointer
 * @param *argv Pointer to an array of command line arguments
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char *argv[])
{
	char *command_line;
	char **args;
	int status;

	/* Check if a filename was passed as an argument*/

	if (argc > 2)
	{
	printf("Error: too many arguments\n");
	return (1);
	}

	else if (argc == 2)
	{
	return (execute_file(argv[1]));
	}


	do {
		print_prompt();
		command_line = mygetline();
		args = parse_command_line(command_line);
		status = execute_command(args);
		free(command_line);
		free(args);
	} while (status);
	return (0);
}
