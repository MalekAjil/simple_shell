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

/**
* main - main function
* Return: 0 on success
*/
int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	char *arguments[MAX_ARGUMENTS];
	char *argToken;
	int argCount = 0;
	pid_t pid;

	while (1)
	{
		printf(">");
		fgets(input, MAX_COMMAND_LENGTH, stdin);
		input[strcspn(input, "\n")] = 0;
		argToken = strtok(input, " ");
		argCount = 0;

		while (argToken != NULL)
		{
			arguments[argCount++] = argToken;
			argToken = strtok(NULL, " ");
		}
		arguments[argCount] = NULL;

		if (cmd_exists(arguments[0]))
		{
			pid = fork();
			if (pid == 0)
			{
				execvp(arguments[0], arguments);
				exit(0);
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
			else
			{
				printf("Fork failed\n");
				return (1);
			}
		}
		else
		{
			printf("Command not found\n");
		}
	}
	return (0);
}
