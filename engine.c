#include "shell.h"

/**
 * Function to handle commands
 * @args :number of arguments
 * Return: 0 on success, 1 on error
 */

int execute_command(char** args)
{
	int status;

	if (args[0] == NULL)
	{
	/* An empty command was entered.*/
	return 1;
	}

	if (strcmp(args[0], "cd") == 0)
		{
			status = execute_cd(args);
		}
	else if (strcmp(args[0], "setenv") == 0)
		{
			status = execute_setenv(args);
		}
	else if (strcmp(args[0], "unsetenv") == 0)
		{
			status = execute_unsetenv(args);
		}
	else if (strcmp(args[0], "alias") == 0)
		{
			status = execute_alias(args);
		}
	else
		{
		/* Fork a child process*/
		pid_t pid = fork();
			if (pid == 0)
			{
			/* Child process */
			if (execvp(args[0], args) == -1)
				{
					perror("shell");
				}
				exit(EXIT_FAILURE);
			}
			else if (pid < 0)
				{
				/*Error forking*/
					perror("shell");
				}
			else
			{
				/*Parent process*/
				do
				{
					waitpid(pid, &status, WUNTRACED);
				} 
				while (!WIFEXITED(status) && !WIFSIGNALED(status));
			}
		}

return status;
}
