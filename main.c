#include "shell.h"

/**
 * main - Entry point
 * @ac: arguments count
 * @av: arguments values
 * @env: environment
 * Return: 0 (success), 1 (failure)
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL;
	char **cmds = NULL;
	size_t n = 0;
	ssize_t count = 0;
	int wcount = 0;

	while (1)
	{
		cmds = NULL;
		if (isatty(0) == 1 && write(1, "($) ", 4) == -1)
			exit(0);
		count = getline(&line, &n, stdin);
		if (count == -1)
		{
			free(line);
			if (isatty(0) != 0)
				write(1, "\n", 1);
			exit(0);
		}
		cmds = str_to_words(line, &wcount);
		if (cmds != NULL)
		{
			if (str_cmp(cmds[0], "exit"))
			{
				free(line);
				free(cmds);
				exit(0);
			}
			exe(cmds, av, env);
		}
		for (n = 0; cmds[n]; n++)
			free(cmds[n]);
		free(cmds);
		line = NULL;
	}
	free(line);
	write(1, "\n", 1);
	if (ac != 1 && av == NULL && env == NULL)
		return (0);
	return (0);
}
