#include "shell.h" 

/**
*exit_shell - function to exit shell
*
*Return: return 0.
*/
int exit_shell(void)
{
	char command[100];

	while (1)
	{
		char prompt[] = "$"
		write(STDOUT_FILENO, prompt, strlen(prompt));
		fgets(command, sizeof(command), stdin);
		command[strcspn(command, "\n")] = '\0';
	if (strcmp(command, "exit") == 0)
		{
		char message[] = "....\n"
		write (STDOUT_FILENO, meassage, strlen(message));
		break;
		}
	}
	return ();
}
