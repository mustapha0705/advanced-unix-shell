#include "shell.h"

/**
 * main - Entry point for shell prototype.
 * Reads user input, tokenizes it into arguments,
 * and stores them in an argv-style array.
 *
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char **argv)
{
    char *line = NULL, **command = NULL;

    while (1)
    {
        line = readline();
        /* Handle EOF (Ctrl+D)*/
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
            {
                if (write(STDOUT_FILENO, "\n", 1) == -1)
                {
                    return (1);
                }
            }
            free(line);
            return (0);
        }

        command = tokeniser(line);
        if (command == NULL)
        {
            free(line);
            continue;
        }

        /* Debug: print parsed arguments */
        int j = 0;
        while (command[j])
        {
            printf("%s\n", command[j++]);
        }

        if (is_builtin(command[0]))
        {
            printf("Handle builtins\n");
            // TODO: handle_builtin(command);
        }
        else
        {
            _execute(command);
        }

        free2Darray(command);
        free(line);
    }

    return (0);
}

void handle_builtin(char **command, char **argv, int *status, int idx)
{
    // handel builtins
}

void exit_shell(char **command, char **argv, int *status, int idx)
{
    // handle shell exit
}

void print_env(char **command, int *status)
{
    // handle printenv
}