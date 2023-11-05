#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **str_to_words(char *str, int *count)
{
	char **words = NULL;
	char *str1 = str;
	int i, c = 0;

	if (str == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		if ((str1[i] == ' ' || str1[i] == '\n') && i > 0 && str1[i - 1] != ' ')
			c++;
		i++;
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
