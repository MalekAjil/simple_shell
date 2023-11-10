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
	char *path = getenv("PATH");

	printf("%s\n%s\n", path, env[0]);
	write(1, "($) ", 4);
	while ((count = get_line(&line, &n, stdin)) != -1)
	{
		cmds = str_to_words(line, &wcount);
		printf("%s\n", line);
		if (cmds != NULL)
		{
			if (str_cmp(cmds[0], "exit"))
			{
				exit(0);
				break;
			}
			exe(cmds, av, env);
		}
		else
			write(2, "Error, No command", 17);
		write(1, "\n($) ", 5);
		free(cmds);
		line = NULL;
	}
	free(line);
	if (ac != 1 && av == NULL && env == NULL)
		return (1);
	return (0);
}
