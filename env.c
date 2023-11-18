#include "shell.h"

/**
 * get_env - return the environ
 * @name: the environment string
 * Return: corresponding string
 */
char *get_env(char *name)
{
	int i = 0, res = 0;
	char c = '=';

	while (environ[i] != NULL)
	{
		res = str_cmp(name, environ[i], c);
		if (!res)
			return (environ[i]);
		i++;
	}
	return (NULL);
}

/**
 * print_env - prints the environment
 *
 * Return: 0 on success
 */
int print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_puts(environ[i]);
	return (0);
}
/**
 * _puts - prints a string
 * @str: string to print
 */
void _puts(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putchar(str[c]);
	_putchar('\n');
}
/**
 * _putchar - prints a character
 * @c: character to print
 *
 * Return: return value of write syscall
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * str_set - sets string with a char
 * @str: the string
 * @c: the charachter
 * @n: number of bytes
 * Return: the char array
 */
char *str_set(char *str, char c, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		str[i] = c;
	return (str);
}
