#include "shell.h"

/**
 * main - Entry point
 * @ac: arguments count
 * @av: arguments values
 * @env: the environment
 * Return: always 0 (success)
 */
int main(int ac, char **av)
{
	char *line = NULL;
	char *cmd[] = {"/bin/ls", NULL};
	lst_cmd *cmdh = NULL;
	size_t n = 0;
	ssize_t count = 0;
	int wcount = 0;
	struct stat st;
	char **env = NULL;

	printf("($) ");
	while ((count = getline(&line, &n, stdin)) != -1)
	{
		wcount = str_to_list(line, &cmdh);
		if (wcount >= 1)
		{
			if (!strcmp(cmdh->cmd, "exit"))
				exit(0);
			if (stat(cmdh->cmd, &st) == 0)
			{
				if (execve(cmdh->cmd, cmd, env) == -1)
					fprintf(stderr, "%s: No such file or directory", argv[0]);
			}
			else
				fprintf(stderr, "%s: %s: command not found", argv[0], cmdh->cmd);
		}
		else
		{
			fprintf(stderr, "%s: %d: Error, No command", argv[0], argc);
		}
		printf("\n($) ");
		wcount = 0;
		free_list(cmdh);
		cmdh = NULL;
	}
	free(line);
	free(cmd[0]);
	return (EXIT_SUCCESS);
}
