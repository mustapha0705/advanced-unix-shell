#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *readline(void);
char **tokeniser(char *);

/**
 * main - Entry point for shell prototype.
 * Reads user input, tokenizes it into arguments,
 * and stores them in an argv-style array.
 *
 * Return: 0 on success, 1 on failure
 */

int main(void){
    char *line = NULL,**command = NULL;
    int i = 0;
    
    
    line = readline();
    /* Handle EOF (Ctrl+D)*/
    if (line == NULL){
        if(isatty(STDIN_FILENO)){
            if(write(STDOUT_FILENO, "\n", 1) == -1){
                return (1);
            }
        }
        free(line);
        return (0);
    }

    command = tokeniser(line);
    if(command == NULL){
        perror("error tokenising");
        free(command);
        free(line);
        return 0;
    }

    /* Debug: print parsed arguments */
    while (command[i])
    {
        printf("%s\n", command[i++]);
    }

    free(command);
    free(line);

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

char **tokeniser(char *line){
    char *token = NULL, *tmp = NULL, *delim = " \t\n";
    char **command = NULL;
    int tok_count = 0, i = 0;

    if(!line){
        return (NULL);
    }

    tmp = strdup(line);
    if(!tmp){
        free(tmp);
        return (NULL);
    }

    token = strtok(tmp, delim);
    if(!token){
        free(tmp);
        return (NULL);
    }

    while(token){
        tok_count++;
        token = strtok(NULL, delim);
    }

    free(tmp);

    /* allocate memory for command */
    command = malloc(sizeof(char *) * (tok_count + 1));
    if(!command){
        free(command);
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