#include "shell.h"

/**
 *set_env - func to set enviroment
 *@variable: variable pointer
 *@value: pointer to the value
 *
 *Return: return i.
 */
int set_env(const char *variable, const char *value)
{
	int i = setenv(variable, value, 1);
	/*the value 1 will overwrite the argument,if it exist*/

	if (i == -1)
	{
		print_Error("Error Setting Enviroment");
	}
	return (i);
}
/**
 *unset_env - function to unset the enviroment
 *@variable: pointer for the variable
 *
 *Return: return i.
 */
int unset_env(const char *variable)
{
	int i = unsetenv(variable);

	if (i == -1)
	{
		print_Error("Error Unsetting Enviroment");
	}
	return (i);
}
/**
 *print_env - function to print the enviroment
 */
void print_env(void)
{
	char **environ = NULL, **env;

	for (env = environ; *env != NULL; env++)
	{
		write(1, *env, str_len(*env));
	}
}
/**
 *print_error - function to print error message
 *@message: message to be outputted
 */
void print_Error(char *message)
{
	write(2, message, str_len(message));
}
