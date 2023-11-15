#include "shell.h"

/**
 * words_count - return words count.
 * @str: the string.
 * Return: int
 */
int words_count(char *str)
{
	int i, c;

	c = 0;
	i = 0;
	for (i = 0; str[i] != '\0' && str[i] != '\n'; i++)
	{
		if ((str[i] == ' ' || str[i] == '\n') && i > 0 && str[i - 1] != ' ')
			c++;
	}
	return (c);
}
/**
 * strtow - splits a string into words.
 * @str: the strig.
 * Return: Concatenated string of arguments values.
 */
char **strtow(char *str)
{
	int i, j, k, c;
	char **s;

	if (str == NULL || str[0] == '\0' || str[0] == '\n')
		return (NULL);
	c = words_count(str);
	if (c == 0)
		return (NULL);

	s = (char **)malloc(sizeof(*str) * c);
	if (s == NULL)
		return (NULL);
	c = 0;
	j = 0;
	for (i = 0; str[i] >= '\0'; i++)
	{
		j++;
		if ((str[i] == ' ' || str[i] == '\n') && i > 0 && str[i - 1] != ' ')
		{
			s[c] = (char *)malloc(sizeof(*str) * j + 1);
			if (s[c] == NULL)
			{
				while (c >= 0)
					free(s[c--]);
				return (NULL);
			}
			for (k = 0; k < j; k++)
				s[c][k] = str[i + 1 - j + k];
			s[c][k] = '\0';
			c++;
			j = 0;
		}
		else if (str[i] == ' ')
			j = 0;
	}
	s[c] = NULL;
	return (s);
}
