/**
*Author: Hassan Muhammad Zali and Malek Alajil
*Description: C program that handles  the PATH, and only calls fork if command exits. 
*/

#include <shell.h>

/**
*cmd_exists - func to check if command exist
*@command: pointing to an array of command. 
*
*Return: return 1 if fails, and 0 otherwise.
*/
int cmd_exists(char *command)
{
	char *path = getenv("PATH");
	char pathCopy[MAX_PATH_LENGTH];
	char *pathToken = strtok(pathCopy, ":");
	strcpy(pathCopy, path);

	while (pathToken != NULL)
 	{
 		char commandPath[MAX_PATH_LENGTH];
		sprintf(commandPath, "%s/%s", pathToken, command);

	if (access(commandPath, F_OK) == 0)
			return (1);
		pathToken = strtok(NULL, ":");
	}
	return (0);
}

/**
*main - main function
*/
int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	char *arguments[MAX_ARGUMENTS];

	while (1)
	{
		printf(">");
		fgets(input, MAX_COMMAND_LENGTH, stdin);
		input[strcspn(input, "\n")] = 0;

	char *argToken = strtok(input, " ");
	int argCount = 0;

	while (argToken != NULL)
	{
		arguments[argCount++] = argToken;
		argToken = strtok(NULL, " ");
	}
	arguments[argCount] = NULL;

	if (cmd_exists(arguments[0]))
	{
		pid_t pid = fork();
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
