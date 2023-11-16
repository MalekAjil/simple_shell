#include "shell.h"

/**
 * free_cmds - frees command array
 * @cmds: the cmd array
 * Return: void
 */
void free_cmds(char **cmds)
{
	int i = 0;

	while (cmds[i])
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
}
