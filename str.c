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
 * str_dup - dupplicates the string
 * @src: source string
 * Return: number of copied charachters
 */
char* str_dup(char *src)
{
	int i = 0;
	char *dest = NULL;

	if (src == NULL)
		return (NULL);
	while (src[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * str_cat - concatenate two strings
 * @dest: destination string
 * @src: source string
 * Return: concatenated string
 */
char* str_cat(char *dest, char *src)
{
	int i = 0, j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src [j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * w_count - counts the number of words in string
 * @str: the string
 * Return: the number of words
 */
int w_count(char *str, char delim)
{
	int i = 0, flag = 1, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != delim && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (str[i + 1] == ' ')
			flag = 1;
	}
	return (count);
}
