#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

char **str_to_words(char *str);
int str_len(char *str);
int str_cmp(char *str1, char *str2, char end);
char *str_dup(char *src);
char *str_cat(char *str1, char *str2);
char *str_cat3(char *str1, char *str2, char *str3);
int str_to_num(char *str);
int w_count(char *str, char delim);
int exe(char **cmds, char **av, char **env);
int words_count(char *str);
char **strtow(char *str);

void free_cmds(char **cmds);
char *get_line(void);
char *get_path(char **cmds, char *line);
int builtin(char **cmds, char *line);
int _fork(char **cmds, char *line, char *path);

int set_env(const char *variable, const char *value);
int unset_env(const char *variable);
char *get_env(char *name);
int print_env(void);
void _puts(char *str);
int _putchar(char c);
char *str_set(char *str, char c, unsigned int n);

#endif
