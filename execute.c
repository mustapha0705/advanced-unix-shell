#include "shell.h"

/**
 * _execute - Executes a command in a child process.
 * @command: An array of strings representing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
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
