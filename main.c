#include "shell.h"

/**
 * main - Entry point
 * @ac: arguments count
 * @argv: arguments values
 *
 * Return: 0 (success), 1 (failure)
 */
int main(void)
{
	char *full_command = NULL, *copy_command = NULL;
	char *token;
	char **argv;
	int i;
	int num_token = 0;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";

	printf("$ ");
	nchars_read = getline(&full_command, &n, stdin);
	copy_command = malloc(sizeof(char) * nchars_read);
	if (copy_command == NULL)
	{
		perror("tsh: memory allocation error");
		return (-1);
	}
	strcpy(copy_command, full_command);
	if (nchars_read == -1)
	{
		printf("Exiting shell.....\n");
		return (-1);
	}
	else
	{
	token = strtok(full_command, delim);
	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	num_token++;
	argv = malloc(sizeof(char *) * num_token);
	token = strtok(copy_command, delim);
	for(i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	free(full_command);
	free(copy_command);
	free(argv);
	}
	return (0);
}
