#include "shell.h"

/**
 *location - search for command location
 *@command: parameter to gake in command
 *
 *Return: return 0.
 */
char *location(char *command)
{
	char *path, *pathcopy, *pathtoken, *filepath;
	int command_length, directory_path;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		pathcopy = strdup(path);
		pathtoken = strtok(pathcopy, ":");
		command_length = strlen(command);
		while (pathtoken != NULL)
		{
			directory_path = strlen(pathtoken);
			filepath = malloc(command_length + directory_path + 2);

			strcpy(filepath, pathtoken);
			strcat(filepath, "/");
			strcat(filepath, command);
			strcat(filepath, "\0");
			if (stat(filepath, &buffer) == 0)
			{
				free(pathcopy);
				return (filepath);
			}
			else
			{
				free(filepath);
				pathtoken = strtok(NULL, ":");
			}
		}
		free(pathcopy);

		if (stat(command, &buffer) == 0)
		{

			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
