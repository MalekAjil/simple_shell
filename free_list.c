#include "shell.h"

/**
 * free_list - frees the list
 * @head: the list header
 * Return: void.
 */
void free_list(lst_cmd *head)
{
	lst_cmd *temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		free(head->cmd);
		free(head);
		head = temp;
	}
}
