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
<<<<<<< HEAD
		perror("tsh: memory allocation error");
		return (-1);
	}
	strcpy(copy_command, full_command);
	if (nchars_read == -1)
=======
		cmds = str_to_words(line, &wcount);
		printf("%s\n", line);
		if (cmds != NULL)
		{
			if (str_cmp(cmds[0], "exit"))
			{
				exit(0);
				break;
			}
			exe(cmds, av, env);
		}
		else
			write(2, "Error, No command", 17);
		write(1, "\n($) ", 5);
		free(cmds);
		line = NULL;
	}
	free(line);
	if (ac != 1 && av == NULL && env == NULL)
		return (1);
	if (set_env(variable, value) != -1)
>>>>>>> origin
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
