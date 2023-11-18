#include "shell.h"

/**
 * builtin - check whether the command is builtin or not
 * @cmds: the commands
 * @line: the line pointer
 * Return: 1 if command is builtin, 0 otherwise
 */
int builtin(char **cmds, char *line)
{
	int st = 0;

	if (!str_cmp(cmds[0], "env", '\0'))
	{
		print_env();
		free_cmds(cmds);
		free(line);
		return (1);
	}
	else if (!str_cmp(cmds[0], "exit", '\0'))
	{
		if (cmds[1] != NULL)
		{
			st = str_to_num(cmds[1]);
		}
		free_cmds(cmds);		
		free(line);
		exit(st);
	}
        return (0);
}
