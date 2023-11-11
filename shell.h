#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * struct lst_cmd - singly linked list to store command and arguments
 * @n: the number of node
 * @cmd: the command string
 * @next: the pointer to the next node
 *
 *
typedef struct lst_cmd
{
	int n;
	char *cmd;
	struct lst_cmd *next;
} lst_cmd;
*/

<<<<<<< HEAD
int main(void);
=======
char **str_to_words(char *str, int *c);
int str_len(char *str);
int str_cmp(char *str1, char *str2);
int str_cpy(char *dist, char *src);
int cmd_exists(char *command);
int exe(char **cmds, char **av, char **env);
int reallocate_memory(char **lineptr, size_t *n);
ssize_t read_line(FILE *stream, char *line, size_t n);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void exit_shell(int status);
int exit_(void);
void print_Error(char *message);
int set_env(const char *variable, const char *value);
int unset_env(const char *variable);
void print_env(void);
>>>>>>> origin

#endif
