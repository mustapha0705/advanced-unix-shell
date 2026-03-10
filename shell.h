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
int is_builtin(char *command);
char *_getpath(char *command);

/* ====== utils.c ======*/
void free2Darray(char **array);
char *_itoa(int n);
void reverse_string(char *str, int len);

/* ====== tools.c ====== */
int is_positive_number(char *str);
int _atoi(char *str);

void handle_builtin(char **command, char **argv, int *status, int idx);
void exit_shell(char **command, char **argv, int *status, int idx);
void print_env(char **command, int *status);