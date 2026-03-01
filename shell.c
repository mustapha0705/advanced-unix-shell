#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *readline(void);

/**
 * main - Entry point for shell prototype.
 * Reads user input, tokenizes it into arguments,
 * and stores them in an argv-style array.
 *
 * Return: 0 on success, 1 on failure
 */

int main(void){
    char *line = NULL, *line_cpy = NULL, *token = NULL;
    char *delim = " \n";
    int argc = 0, i = 0;
    char **argv;
    size_t len = 0;
    
    /* read line */
    line = readline();
    if (line == NULL){
        perror("Error reading line");
        free(line);
        return (1);
    }

    /* preserve original input for second tokenization pass */
    line_cpy = strdup(line);
    if(!line_cpy){
        perror("strdup failed");
        free(line);
        return (1);
    }

    /* First pass: count number of arguments */
    token = strtok(line, delim);
    while (token)
    {
        token = strtok(NULL, delim);
        argc++;
    }

    argv = malloc(sizeof(char *) * (argc+1));
    if(!argv){
        perror("Failed to allocate memory");
        free(line);
        free(line_cpy);
        return (1);
    }

    /* Second pass: populate argv array */
    token = strtok(line_cpy, delim);
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

    free(line);
    free(line_cpy);
    free(argv);

    return (0);
}

char *readline(void){
    char *line = NULL;
    size_t len = 0;

    if (isatty(STDIN_FILENO)){
        if(write(STDOUT_FILENO, "($) ", 4) == -1){
            return (NULL);
        }
    }
    
    if(getline(&line, &len, stdin) == -1){
        free(line);
        return (NULL);
    }

    return (line);
}