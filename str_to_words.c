#include "shell.h"

/**
 * str_to_words - split the string into words
 * @str: the string
 * @count: words count
 * Return: the words array
 */
char **str_to_words(char *str, int *count)
{
	char **words = NULL;
	char *str1 = str;
	int i, c = 0;

	if (str == NULL)
		return (NULL);
	while (*str1 != '\0')
	{
		if ((*str1 == ' ' || *str1 == '\n') && *(str1 - 1) != ' ')
			c++;
		str1++;
	}
	words = malloc(sizeof(char *) * (c + 1));
	if (words == NULL)
		return (NULL);
	for (i = 0, str1 = str; ; i++, str1 = NULL)
	{
		words[i] = strtok(str1, " \n");
		if (words[i] == NULL)
			break;
	}
	*count = c;
	return (words);
}
