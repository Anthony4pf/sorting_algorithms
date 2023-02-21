#include "sort.h"

/**
*bubble_sort - sort an array using bubble sort
*@array: array to be sorted
*@size: size of the array
*Return: void
*/

void bubble_sort(int *array, size_t size)
{
	int i, j;
	int temp;
	int swapped;

	for (i = size - 1; i >= 0; i--)
	{
		swapped = 0;

		for (j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
}
