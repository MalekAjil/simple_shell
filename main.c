#include "shell.h"

/**
 * exe - execute the command
 * @cmdstr: the command to be executed
 * @cmd: cmd array
 * Return: status
 */
int exe(char *cmdstr, char *cmd[])
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
		if (execv(cmdstr, cmd) == -1)
		{
			printf("./shell: %s: command not found", cmdstr);
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
	char *cmd[] = {"/bin/ls", NULL};
	lst_cmd *cmdh = NULL;
	size_t n = 0;
	ssize_t count = 0;
	int wcount = 0;

	printf("($) ");
	while (1)
	{
		count = getline(&line, &n, stdin);
		if (count == -1)
			break;
		wcount = str_to_list(line, &cmdh);
		if (wcount > 1)
			printf("Too many arguments");
		else if (wcount == 1)
		{
			if (exe(cmdh->cmd, cmd) == 1)
			{
				exit(1);
			}
		}
		else
			printf("Error, No command");
		printf("\n($) ");
		wcount = 0;
		cmdh = NULL;
	}
	if (ac != 1 && av == NULL && env == NULL)
		return (1);
	return (0);
}
