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

int main(int ac, char **argv);
void exec(char **argv);
char *location(char *command);

#endif
