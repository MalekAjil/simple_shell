#include "shell.h"

/**
 * str_len - return string length
 * @str: the string
 * Return: the length
 */
int str_len(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
