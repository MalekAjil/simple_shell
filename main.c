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
	char *prompt = "($)";
	char *lineptr;
	size_t n = 0;

	(void) ac; (void)argv;

	printf("%s", prompt);
	printf("%s\n", lineptr);
	getline(&lineptr, &n, stdin);

	free(lineptr);
	return (0);
}
