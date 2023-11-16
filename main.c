#include "shell.h"

/**
 * main - Entry point
 * 
 * Return: 0 (success), 1 (failure)
 */
int main(void)
{
	char *line = NULL, *PATH = NULL, *dir = NULL;
	char **cmds = NULL;

	signal(SIGINT, SIG_IGN);
	PATH = get_env("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		cmds = NULL;
		if (isatty(0) == 1 && write(1, "($) ", 4) == -1)
			exit(0);
		get_line(line);
		if (*line != '\0')
		{
			cmds = str_to_words(line);
			if (cmds == NULL)
			{
				free(line);
				continue;
			}
			dir = get_path(cmds, PATH);
			if (builtin(cmds, line) != 0)
				continue;
			_fork(cmds, line, dir);
		}
		else
			free(line);
	}
	return (0);
}
