#include "sort.h"

/**
*insertion_sort_list - sorts a list in ascending order using the insertion sort
*@list: address of the head of the list
*Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr1, *ptr2, *ptr;

	if (!list || !*list || !(*list)->next)
		return;

	ptr1 = (*list)->next;

	while (ptr1 != NULL)
	{
		ptr = ptr1->next;
		ptr2 = ptr1->prev;

		while (ptr2 != NULL && ptr2->n > ptr1->n)
		{
			if (ptr1->next != NULL)
				ptr1->next->prev = ptr2;
			if (ptr2->prev != NULL)
				ptr2->prev->next = ptr1;

			ptr2->next = ptr1->next;
			ptr1->prev = ptr2->prev;
			ptr2->prev = ptr1;
			ptr1->next = ptr2;

			if (ptr2 == *list)
				*list = ptr1;

			print_list((const listint_t *)*list);
			ptr2 = ptr1->prev;
		}
		ptr1 = ptr;
	}
}
