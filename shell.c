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
    int idx = 0;
    int status = 0;
    (void)argc;

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

        idx++;
        command = tokeniser(line);
        if (command == NULL)
        {
            free(line);
            continue;
        }

        if (is_builtin(command[0]))
        {
            handle_builtin(command, argv, &status, idx);
        }
        else
        {
            _execute(command, argv, idx);
        }

        free2Darray(command);
        free(line);
    }

    return (0);
}
