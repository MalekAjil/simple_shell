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

/**
 * str_cmp - compare two strings
 * @str1: the first string
 * @str2: the second string
 * Return: 1 if str1 equals str2, 0 otherwise
 */
int str_cmp(char *str1, char *str2)
{
	int n1, n2;

	n1 = str_len(str1);
	n2 = str_len(str2);
	if (n1 != n2)
		return (0);
	n1 = 0;
	while (str1[n1] != '\0')
	{
		if (str1[n1] != str2[n1])
			return (0);
		n1++;
	}
	return (1);
}

/**
 * str_cpy - copy string
 * @dist: distenation string
 * @src: source string
 * Return: number of copied charachters
 */
int str_cpy(char *dist, char *src)
{
	int n = 0, i = 0;

	if (src == NULL)
		return (-1);
	n = str_len(src);
	dist = malloc(sizeof(char) * n);
	if (dist == NULL)
		return (-1);
	while (src[i] != '\0')
	{
		dist[i] = src[i];
		i++;
	}
	return (n);
}
