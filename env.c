#include "shell.h"

/**
 * @int execute_cd(char** args):handle cd
 * @int execute_setenv(char** args): handle setenv
 * @int execute_unsetenv(char** args):handle unsetenv
 * @int execute_alias(char** args):handle alias
 * @int execute_file(char *filename): handle file execution
 * Return: int
 */


int execute_cd(char** args)
	{
	if (args[1] == NULL)
    {
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("shell");
        }
    }
    return 1;
}

int execute_setenv(char** args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "shell: expected argument to \"setenv\"\n");
    }
    else
    {
        if (setenv(args[1], args[2], 1) != 0)
        {
            perror("shell");
        }
    }
    return 1;
}

int execute_unsetenv(char** args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "shell: expected argument to \"unsetenv\"\n");
    }
    else
    {
        if (unsetenv(args[1]) != 0)
        {
            perror("shell");
        }
    }
    return 1;
}

int execute_alias(char** args)
{
    if (args[1] == NULL)
    {
        // Print all aliases
        char *name, *value;
        for (int i = 0; environ[i] != NULL; i++)
        {
            name = strtok(environ[i], "=");
            value = strtok(NULL, "=");
            printf("%s='%s'\n", name, value);
        }
    }
    else if (args[2] == NULL)
    {
        // Print the given aliases
        for (int i = 1; args[i] != NULL; i++)
        {
            char *name, *value;
            for (int j = 0; environ[j] != NULL; j++)
            {
                name = strtok(environ[j], "=");
                value = strtok(NULL, "=");
                if (strcmp(name, args[i]) == 0)
                {
                    printf("%s='%s'\n", name, value);
                    break;
                }
            }
        }
    }
    else
    {
        // Set the given aliases
        for (int i = 1; args[i] != NULL; i += 2)
        {
            if (args[i + 1] == NULL)
            {
                break;
            }
            if (setenv(args[i], args[i + 1], 1) != 0)
            {
                perror("shell");
            }
        }
    }
    return 1;
}

int execute_file(char *filename)
{
    int status;
    char *command_line;
    char **args;
    FILE *file;

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("shell");
        return 1;
    }

    // Read the file line by line
    while (1)
    {
        command_line = getline();

        if (feof(file))
        {
            free(command_line);
            break;
        }

        args = parse_command_line(command_line);
        status = execute_command(args);

        free(command_line);
        free(args);
    }

    // Close the file
    fclose(file);

    return status;
}
