#include "shell.h"

/**
*exit_shell - function to exit shell
*
*Return: return 0.
*/
int exit_shell(void)
{
	char command[100];
	char *prompt;
	char *message;

	while (1)
	{
		printf("$)");
		fgets(command, sizeof(command), stdin);
		command[strcspn(command, "\n")] = '\0';
		if (strcmp(command, "exit") == 0)
		{
			printf("...\n");
			break;
		}
		prompt[] = "$";
		write(STDOUT_FILENO, prompt, strlen(prompt));
		fgets(command, sizeof(command), stdin);
		command[strcspn(command, "\n")] = '\0';
		if (strcmp(command, "exit") == 0)
		{
			message = "....\n";
			write(STDOUT_FILENO, meassage, strlen(message));
			break;
		}
	}
	return (0);
}
