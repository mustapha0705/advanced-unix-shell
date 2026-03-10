#include "shell.h"

/**
 * tokenizer - Tokenizes a string into an array of strings.
 * @line: The string to tokenize.
 *
 * Return: An array of strings (tokens), or NULL on failure.
 */
char **tokeniser(char *line)
{
    char *token = NULL, *tmp = NULL, *delim = " \t\n";
    char **command = NULL;
    int tok_count = 0, i = 0;

    if (!line)
    {
        return (NULL);
    }

    tmp = strdup(line);
    if (!tmp)
    {
        return (NULL);
    }

    token = strtok(tmp, delim);
    if (!token)
    {
        free(tmp);
        return (NULL);
    }

    while (token)
    {
        tok_count++;
        token = strtok(NULL, delim);
    }

    free(tmp);

    /* allocate memory for command */
    command = malloc(sizeof(char *) * (tok_count + 1));
    if (!command)
    {
        return (NULL);
    }

    token = strtok(line, delim);
    while (token)
    {
        command[i] = strdup(token);
        token = strtok(NULL, delim);
        i++;
    }

    command[i] = NULL;

    return (command);
}