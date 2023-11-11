#include "shell.h"

/**
 * main - Entry point
 * @ac: arguments count
 * @argv: arguments values
 *
 * Return: 0 (success), 1 (failure)
 */
int main(int ac, char **argv)
{
	char *prompt = ("$");
	char *token;
	char *lineptr = NULL, *lineptr_copy = NULL;
	int i;
	int num_token = 0;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";

	(void)ac;

	while (1)
	{
	printf("%s", prompt);
	nchars_read = getline(&lineptr, &n, stdin);
	
	if (nchars_read == -1)
	{
		printf("Exiting shell");
		return (-1);
	}
	lineptr_copy = malloc(sizeof(char) * nchars_read);
	if (lineptr == NULL)
	{
		perror("tsh: memory allocation error");
		return (-1);
	}
	strcpy(lineptr_copy, lineptr);

	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	num_token++;
	argv = malloc(sizeof(char *) * num_token);
	token = strtok(lineptr_copy, delim);
	for(i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	exec(argv);
	}
	free(lineptr_copy);
	free(lineptr);

	return (0);
}
