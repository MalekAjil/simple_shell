#include "shell.h"

/**
 * _fork - execute the command
 * @cmds: the commands
 * @line: the line pointer
 * @path: a copy of path
 * Return: the status
 */
int _fork(char **cmds, char *line, char *path)
{
	int stat, res, es;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		res =  execve(path, cmds, environ);
		if (res == -1)
		{
			perror(cmds[0]);
			free_cmds(cmds);
			free(line);
			exit(127);
		}
	}
	wait(&stat);
	if (WIFEXITED(stat))
	{
		es = WEXITSTATUS(stat);
	}
	free_cmds(cmds);
	if (line != NULL)
		free(line);
	return (es);
}
