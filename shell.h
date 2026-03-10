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
int _execute(char **command, char **argv, int idx);
char *_getpath(char *command);

/* ====== builtins.c ====== */
int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idx);
void exit_shell(char **command, char **argv, int *status, int idx);
void print_env(char **command, int *status);

/* ====== utils.c ======*/
void free2Darray(char **array);
char *_itoa(int n);
void reverse_string(char *str, int len);
void print_error(char *name, char *cmd, int idx);

/* ====== tools.c ====== */
int is_positive_number(char *str);
int _atoi(char *str);