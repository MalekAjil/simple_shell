#include "shell.h"

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
