#include "shell.h"

/**
 * exe - execute the command
 * @cmdstr: the command to be executed
 * @cmd: cmd array
 * Return: status
 */
int exe(char **cmds, char **av, char **env)
{
	pid_t pid;
	int stat;

	pid = fork();
	if (pid < 0)
	{
		perror("failed");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(cmds[0], cmds, env) == -1)
		{
			printf("%s: %s: command not found", av[0], cmds[0]);
			return (1);
		}
	}
	else
	{
		waitpid(pid, &stat, 0);
		if (WIFEXITED(stat) && WEXITSTATUS(stat) != 0)
			printf("command faild with status: %d\n", WEXITSTATUS(stat));
	}
	return (0);
}

/**
 * main - Entry point
 * @ac: arguments count
 * @av: arguments values
 * Return: always 0 (success)
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL;
	char **cmds = NULL;
	size_t n = 0;
	ssize_t count = 0;
	int wcount = 0, i = 0;

	printf("($) ");
	while ((count = getline(&line, &n, stdin)) != -1)
	{
		cmds = str_to_words(line, &wcount);
		if (cmds != NULL)
		{
			exe(cmds, av, env);
		}
		else
			printf("Error, No command");
		printf("\n($) ");
		for (i = 0; i < wcount; i++)
			free(cmds[i]);
		free(cmds);
	}
	if (ac != 1 && av == NULL && env == NULL)
		return (1);
	return (0);
}
