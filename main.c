#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Entry point for shell prototype.
 * Reads user input, tokenizes it into arguments,
 * and stores them in an argv-style array.
 *
 * Return: 0 on success, 1 on failure
 */

int main(void){
    char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
    char *delim = " \n";
    int argc = 0, i = 0;
    char **argv;
    size_t len = 0;
    
    /* Display prompt and read input */
    printf("mustapha$ ");
    fflush(stdout);
    if(getline(&cmd, &len, stdin) == -1){
        perror("An erro occured while reading line");
        free(cmd);
        return (1);
    }

    /* preserve original input for second tokenization pass */
    cmd_cpy = strdup(cmd);
    if(!cmd_cpy){
        perror("strdup failed");
        free(cmd);
        return (1);
    }

    /* First pass: count number of arguments */
    token = strtok(cmd, delim);
    while (token)
    {
        token = strtok(NULL, delim);
        argc++;
    }

    argv = malloc(sizeof(char *) * (argc+1));
    if(!argv){
        perror("Failed to allocate memeory");
        free(cmd);
        free(cmd_cpy);
        return (1);
    }

    /* Second pass: populate argv array */
    token = strtok(cmd_cpy, delim);
    while (token)
    {
        argv[i] = token;
        token = strtok(NULL, delim);
        i++;
    }
    argv[i] = NULL;
    
    /* Debug: print parsed arguments */
    int j = 0;
    while (argv[j])
    {
        printf("%s\n", argv[j++]);
    }
    printf("\n");

    free(cmd);
    free(cmd_cpy);
    free(argv);

    return (0);
}