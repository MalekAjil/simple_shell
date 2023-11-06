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
			write(2, ": command not found", 20);
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
		}
	}
	return (0);
}

/**
* cmd_exists - func to check if command exist
* @command: pointing to an array of command.
* Return: return 1 if fails, and 0 otherwise.
*/
int cmd_exists(char *command)
{
	char *path = getenv("PATH");
	char pathCopy[MAX_PATH_LENGTH];
	char commandPath[MAX_PATH_LENGTH];
	char *pathToken = strtok(pathCopy, ":");

	strcpy(pathCopy, path);
	while (pathToken != NULL)
	{
		sprintf(commandPath, "%s/%s", pathToken, command);
		if (access(commandPath, F_OK) == 0)
			return (1);
		pathToken = strtok(NULL, ":");
	}
	return (0);
}

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

	write(1, "($) ", 4);
	while ((count = getline(&line, &n, stdin)) != -1)
	{
		cmds = str_to_words(line, &wcount);
		if (cmds != NULL && cmd_exists(cmds[0]))
		{
			exe(cmds, av, env);
		}
		else
			write(2, "Error, No command", 17);
		write(1, "\n($) ", 5);
		free(cmds);
	}
	if (ac != 1 && av == NULL && env == NULL)
		return (1);
	return (0);
}
