#include "shell.h"

/**
 * read_line - Read a line of input from the user.
 *
 * Return: A pointer to the read line.
 */
char *readline(void)
{
    char *line = NULL;
    size_t len = 0;

    if (isatty(STDIN_FILENO))
    {
        if (write(STDOUT_FILENO, "($) ", 4) == -1)
        {
            return (NULL);
        }
    }

    if (getline(&line, &len, stdin) == -1)
    {
        free(line);
        return (NULL);
    }

    return (line);
}