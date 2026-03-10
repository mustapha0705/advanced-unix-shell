#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *readline(void);
char **tokeniser(char *line);
int _execute(char **command);
void free2Darray(char **array);
int is_builtin(char *command);
char *_getpath(char *command);

void handle_builtin(char **command, char **argv, int *status, int idx);
void exit_shell(char **command, char **argv, int *status, int idx);
void print_env(char **command, int *status);