#include "shell.h"

/**
 *exec - function to execute
 *@argv: argument vector
 */
void exec(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		command = argv[0];
		actual_command = location(command);
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
