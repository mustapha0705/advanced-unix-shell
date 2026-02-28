#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(void){
    char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
    char *delim = " \n";
    int argc = 0, i = 0;
    char **argv;

    size_t len;
    
    printf("$ ");
    if(getline(&cmd, &len, stdin) == -1){
        perror("An erro occured while reading line");
        free(cmd);
        return 1;
    }

    cmd_cpy = strdup(cmd);
    token = strtok(cmd, delim);

    while (token)
    {
        token = strtok(NULL, delim);
        argc++;
    }

    argv = malloc(sizeof(char *) * argc);

    token = strtok(cmd_cpy, delim);

    while (token)
    {
        argv[i] = token;
        token = strtok(NULL, delim);
        i++;
    }
    argv[i] = NULL;
    
    int j = 0;

    while (argv[j])
    {
        printf("%s\n", argv[j++]);
    }
    printf("\n");

    free(cmd), free(cmd_cpy), free(token);

    return (0);
}