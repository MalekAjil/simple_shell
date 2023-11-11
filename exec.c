#include "shell.h"

/**
 *exec - function to execute
 *@argv: argument vector
 */
void exec(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		};
	}
}
