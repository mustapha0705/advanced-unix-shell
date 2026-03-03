#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char *readline(void);
char **tokeniser(char *line);
int _execute(char **command);
void free2Darray(char **array);

/**
 * main - Entry point for shell prototype.
 * Reads user input, tokenizes it into arguments,
 * and stores them in an argv-style array.
 *
 * Return: 0 on success, 1 on failure
 */

int main(void)
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

        if (strchr(command[0], '/'))
        {
            int status;
            status = _execute(command);
        }

        free2Darray(command);
        free(line);
    }

    return (0);
}

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

int _execute(char **command)
{
    int status = 0;

    pid_t pid;

    pid = fork();

    if(pid < 0){
        perror("fork");
        return (-1);
    }

    if (pid == 0)
    {
        int val = execve(command[0], command, NULL);
        if (val == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }

        return (status);
    }
    else
    {
        waitpid(pid, &status, 0);
    }

    return (status);
}

void free2Darray(char **array)
{
    int i;

    if (!array)
    {
        return;
    }

    for (i = 0; array[i]; i++)
    {
        free(array[i]);
        array[i] = NULL;
    }

    free(array);
    array = NULL;
}