#include "shell.h"

/**
 * str_to_num - converts string to number
 * @str: the string
 * Return: the correspounding number
 */
int str_to_num(char *str)
{
	int i, j, sg;
	unsigned int nb;

	nb = 0;
	sg = 1;
	j = strlen(str);
	for (i = 0; i < j; i++)
	{
		if (str[i] == 45)
			sg *= -1;
		if (str[i] > 47 && str[i] < 58)
		{
			nb = str[i] - 48;
			while (str[i + 1] > 47 && str[i + 1] < 58)
			{
				++i;
				nb *= 10;
				nb += str[i] - 48;
			}
			break;
		}
	}
	nb *= sg;
	return (nb);
}
