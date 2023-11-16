#include "shell.h"

/**
 * builtin - check whether the command is builtin or not
 * @cmds: the commands
 * @line: the line pointer
 * Return: 1 if command is builtin, 0 otherwise
 */
int builtin(char **cmds, char *line)
{
	if (str_cmp(cmds[0], "env"))
	{
		print_env();
		free_cmds(cmds);
		free(line);
		return (1);
	}
	else if (str_cmp(cmds[0], "exit"))
	{
		free_cmds(cmds);
		free(line);
		exit(0);
	}
        return (0);
}
