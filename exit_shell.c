#include "shell.h"

/**
*exit_shell - function to exit shell
*@status: status of the shell after command
*/
void exit_shell(int status)
{
	write(2, &status, sizeof(int));
	_exit(status);
}
/**
*exit -  main function to handle exit
*Return: rturn 0.
*/
int exit_(void)
{
	char command[] = "exit 2";
	char *command_name;
	int status;
	char *status_str = strtok(NULL, " ");

	command_name = strtok(command, " ");
	if (command_name != NULL && strcmp(command_name, "exit") == 0)
	{
		if (status_str != NULL)
		{
			status = atoi(status_str);
			exit_shell(status);
		}
		else
		{
			write(2, "Invalid command: Usage: exit status\n", 34);
		}
	}
	else
	{
		write(2, "Command not recognized\n", 24);
	}
	return (0);
}
