#include "shell.h"

/**
 * main - Entry point
 * @ac: arguments count
 * @av: arguments values
 * @env: the environment
 * Return: always 0 (success)
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL;
	char *cmd[] = {"/bin/ls", NULL};
	lst_cmd *cmdh = NULL;
	size_t n = 0;
	ssize_t count = 0;
	int wcount = 0;
	struct stat st;

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
					printf("could not be execyted");
			}
			else
				printf("./shell: %s: command not found", cmdh->cmd);
		}
		else
			printf("Error, No command");
		printf("\n($) ");
		wcount = 0;
		free_list(cmdh);
		cmdh = NULL;
	}
	if (ac != 1 && av == NULL && env == NULL)
		return (1);
	return (0);
}
