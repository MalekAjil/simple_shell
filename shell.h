#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 100
#define MAX_ARGUMENTS 10


/**
 * struct lst_cmd - singly linked list to store command and arguments
 * @n: the number of node
 * @cmd: the command string
 * @next: the pointer to the next node
 */
typedef struct lst_cmd
{
	int n;
	char *cmd;
	struct lst_cmd *next;
} lst_cmd;

char **str_to_words(char *str, int *c);
int str_len(char *str);
int cmd_exists(char *command);
int exe(char **cmds, char **av, char **env);

#endif
