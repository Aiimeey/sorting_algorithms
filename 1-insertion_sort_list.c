#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      using the Insertion Sort algorithm
 * @list: A pointer to a pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;
	int check;

	if (!list || !(*list) || !(*list)->next)
		return;
	do {check = 0;
		temp = *list;
		while (temp->next)
		{
			if (temp->n > temp->next->n)
			{	current = temp->next;

				if (current->next)
				{
					temp->next = current->next;
					temp->next->prev = temp;
				}
				else if (!current->next)
					temp->next = NULL;

				if (temp->prev)
				{
					current->prev = temp->prev;
					current->prev->next = current;
				}
				else if (!temp->prev)
				{
					current->prev = NULL;
					(*list) = current;
				}

				temp->prev = current;
				current->next = temp;

				check = 1;
				print_list(*list);
				break;
			} temp = temp->next;
		}
	} while (check);
}
