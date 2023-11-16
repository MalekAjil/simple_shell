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
int str_cmp(char *str1, char *str2);
char *str_dup(char *src);
int str_words(char *str);
int exe(char **cmds, char **av, char **env);
int words_count(char *str);
char **strtow(char *str);

void free_cmds(char **cmds);
ssize_t get_line(char *lineptr);
char* get_path(char **cmds, char *line, char *path);
int builtin(char **cmds, char *line);
int _fork(char **cmds, char *line, char *path);

int set_env(const char *variable, const char *value);
int unset_env(const char *variable);
char *get_env(const char *name);
void print_env(void);
void _puts(char *str);
int _putchar(char c);
char *str_set(char *str, char c, unsigned int n);

#endif
