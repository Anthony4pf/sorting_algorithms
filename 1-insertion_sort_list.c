#include "sort.h"

/**
*insertion_sort_list - sorts a list in ascending order using the insertion sort
*@list: address of the head of the list
*Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *ptr1;
	int temp = 0;


	if (!list || !(*list)->next || !*list)
		return;

	ptr1 = (*list)->next;

	while (ptr1 != NULL)
	{
		temp = ptr1->n;
		ptr = ptr1->prev;

		while(ptr != NULL)
		{
			if (ptr->n > temp)
			{
				if (ptr1->next != NULL)
					ptr1->next->prev = ptr;
				if (ptr->prev != NULL)
					ptr->prev->next = ptr1;

				ptr->next = ptr1->next;
				ptr1->prev = ptr->prev;
				ptr->prev = ptr1;
				ptr1->next = ptr;
			}
			ptr = ptr1->prev;
		}
		ptr1 = ptr->next;
	}
}
