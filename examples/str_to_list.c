#include "shell.h"

/**
 * str_to_list - convert a string to list of strings
 * @str: the string
 * @head: list head pointer
 * Return: words count
 */
int str_to_list(char *str, lst_cmd **head)
{
	lst_cmd *new, *tmp;
	int i = 0, j = 0, charc = 0, wcount = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] == ' ' || str[i] == '\n') && i > 0 && str[i - 1] != ' ')
		{
			new = malloc(sizeof(lst_cmd));
			new->n = wcount;
			new->cmd = malloc(sizeof(char) * charc);
			for (j = 0; j < charc; j++)
				new->cmd[j] = str[i - charc + j];
			new->next = NULL;
			if (*head == NULL)
				*head = new;
			else
			{
				tmp = *head;
				while (tmp != NULL)
					tmp = tmp->next;
				tmp = new;
			}
			charc = 0;
			wcount++;
		}
		i++;
		charc++;
	}
	return (wcount);
}
