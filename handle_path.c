#include "shell.h"

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