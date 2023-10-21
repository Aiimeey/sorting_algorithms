#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;
	int check;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		check = 0;
		temp = *list;
		while (temp->next) {
			if (temp->n > temp->next->n) {
                current = temp->next;

				if(!temp->prev)
				{
					temp->next = current->next;
					current->next = temp;
					current->prev = NULL;
					temp->prev = current;
					temp->next->prev = temp;
					(*list) = current;
				}
				else if(!current->next) {
					
					temp->prev->next = current;
					current->next = temp;
					temp->next = NULL;
					current->prev= temp->prev;
					temp->prev = current;	
				}
				else
				{
					temp->next = current->next;
					current->next = temp;

					temp->prev->next = current;
					current->prev = temp->prev;

					temp->prev = current;
					temp->next->prev = temp;
				}


				check = 1;
				print_list(*list);
				break;
			}
			temp = temp->next;
		}
	} while (check);                  
}
