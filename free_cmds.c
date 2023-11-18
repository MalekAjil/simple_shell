#include "shell.h"

/**
 * free_cmds - frees command array
 * @cmds: the cmd array
 * Return: void
 */
void free_cmds(char **cmds)
{
	int i = 0;

	if (cmds == NULL)
		return;
	while (cmds[i] != NULL)
		i++;
	while(cmds[i])
	{
		free(cmds[i]);
		i--;
	}
	if (cmds != NULL)
		free(cmds);
}
