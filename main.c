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
		write(1, "($) ", 4);
		count = getline(&line, &n, stdin);
		if (count == -1)
			return (0);
		cmds = str_to_words(line, &wcount);
		if (cmds != NULL)
		{
			if (str_cmp(cmds[0], "exit"))
			{
				return (0);
			}
			exe(cmds, av, env);
		}
		else
			write(2, "Error, No command", 17);
		free(cmds);
		line = NULL;
	}
	free(line);
	write(1, "\n", 1);
	if (ac != 1 && av == NULL && env == NULL)
		return (0);
	return (0);
}
