#include "shell.h"

/**
 * exe - execute the command
 * @cmds: the command to be executed
 * @av: argument value
 * @env: environment
 * Return: 0 on success, 1 on failure
 */
int exe(char **cmds, char **av, char **env)
{
	pid_t pid;
	int stat;
	char c;

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
			write(2, av[0], str_len(av[0]));
			write(2, ": ", 2);
			write(2, cmds[0], str_len(cmds[0]));
			write(2, ": command not found\n", 20);
			return (1);
		}
	}
	else
	{
		waitpid(pid, &stat, 0);
		if (WIFEXITED(stat) && WEXITSTATUS(stat) != 0)
		{
			write(2, "command faild with status: ", 28);
			c = '0' + WEXITSTATUS(stat);
			write(2, &c, 1);
			write(2, "\n", 1);
			return (1);
		}
	}
	return (0);
}
