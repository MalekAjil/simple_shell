#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **str_to_words(char *str, int *count)
{
	char **words = NULL;
	char *tmp = str;
	size_t len;
	int c = 0;

	while (*tmp != '\0')
	{
		words = realloc(words, sizeof(char *) * (c + 1));
		if (words == NULL)
		{
			printf("Usage: error\n");
			return (NULL);
		}
		len = strcspn(tmp, " \n");
		words[c] = malloc(sizeof(char) * (len));
		if (words[c] == NULL)
		{
			printf("Usage: error\n");
			return (NULL);
		}
		strncpy(words[c], tmp, len);
		c++;
		tmp += len;
		tmp += strspn(tmp, " \n");
	}
	*count = c;
	return words;
}
