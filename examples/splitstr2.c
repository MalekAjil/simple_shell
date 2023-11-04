#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(char *str, char *delim)
{
	char **words = NULL;
	int count = 0;
	char *pos = str;
	while (*pos != '\0')
	{
		size_t len = strcspn(pos, delim);
		words = realloc(words, sizeof(char *) * (count + 1));
		if (words == NULL)
		{
			printf("Memory allocation error\n");
			exit(1);
		}
		words[count] = malloc(sizeof(char) * (len + 1));
		if (words[count] == NULL)
		{
			printf("Memory allocation error\n");
			exit(1);
		}
		strncpy(words[count], pos, len);
		words[count][len] = '\0';
		count++;
		pos += len;
		pos += strspn(pos, delim);
	}
	return words;
}

int main()
{
	char str[] = "This is a test string";
	char delim[] = " ";
	char **words = split_string(str, delim);
	int i;
	
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", words[i]);
	}
	for (i = 0; i < 5; i++)
	{
		free(words[i]);
	}
	free(words);
	return 0;
}
