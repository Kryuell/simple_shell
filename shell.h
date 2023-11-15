#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>

extern char **environ;

#define DELIM " \t\n"

char *readLine(void);
char **parser(char *line);
char *_getenv(char *variable);
char *_getpath(char *commands);
char *my_strdup(const char *str);
int my_strcmp(char *s1, char *s2);
int my_strlen(char *s);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, char *src);

int my_execute(char **command, char **argv, int idex);
void freeArray(char **arr);
char *_itoa(int n);
void print_error(char *name, char *cmd, int idex);
void rev_string(char *str, int len);
int _atoi(char *str);
int is_positive_n(char *str);
int _atoi(char *str);



int hand_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idex);
void exit_shell(char **command, char **argv, int *status, int idex);
void print_env(char **command, int *status);


#endif
