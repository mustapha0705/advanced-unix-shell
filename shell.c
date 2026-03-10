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
    char *full_cmd;
    int status = 0;

    pid_t pid;

    full_cmd = _getpath(command[0]);
    if (!full_cmd)
    {
        return 127;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return (-1);
    }

    if (pid == 0)
    {
        int val = execve(full_cmd, command, environ);
        if (val == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }

        return (status);
    }

    else
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
            free(full_cmd);
            return -1;
        }
    }
    free(full_cmd);

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

int is_builtin(char *command)
{
    char *builtins[] =
        {
            "exit", "env", "setenv", "unsetenv",
            "cd", NULL};
    int i;

    for (i = 0; builtins[i]; i++)
    {
        if (strcmp(command, builtins[i]) == 0)
            return (1);
    }
    return (0);
}

char *_getpath(char *command)
{
    char *path_env, *full_cmd, *dir, *path_copy;
    int i;
    struct stat st;

    /* Check if the command includes a '/' */
    for (i = 0; command[i]; i++)
    {
        if (command[i] == '/')
        {
            if (stat(command, &st) == 0)
                return (strdup(command));

            return (NULL);
        }
    }

    /* Get the PATH environment variable */
    path_env = getenv("PATH");
    if (!path_env)
        return NULL;

    path_copy = strdup(path_env);
    if (!path_copy)
        return NULL;

    for (dir = strtok(path_copy, ":"); dir; dir = strtok(NULL, ":"))
    {

        full_cmd = malloc(strlen(dir) + strlen(command) + 2);
        if (!full_cmd)
        {
            free(path_copy);
            return (NULL);
        }

        /* Construct the full command path */
        strcpy(full_cmd, dir);
        strcat(full_cmd, "/");
        strcat(full_cmd, command);

        if (stat(full_cmd, &st) == 0)
        {
            free(path_copy);
            return (full_cmd);
        }

        free(full_cmd);
    }

    free(path_copy);
    return (NULL);
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