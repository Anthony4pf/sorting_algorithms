#include "sort.h"


/**lomuto_partition - partition an array around a pivot
*@array: array to be partitioned
*@lb: lowerbound of the array
*@ub: upperbound of the arrat
*Return: position of the pivot
*/

size_t lomuto_partition(int *array, size_t lb, size_t ub)
{
	int pivot, current_index;
	int temp, i = 0;

	pivot = array[ub];
	current_index = array[lb];

	for (i = current_index; i < ub; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			array[i] = array[current_index];
			array[current_index] = temp;
			current_index++;			
		}
	}
	temp = array[ub];
	array[ub] = array[current_index];
	array[current_index] = temp;

	return current_index;
}

/**quicksort - sort an array using quick sort
*@array - array to be sorted
*@lb: lowerbound of the array
*@ub: upperbound of the array
*@Return: void
*/

void quicksort(int *array, size_t lb, size_t ub)
{
	size_t loc;

	if (lb < ub)
	{
		loc = lomuto_partition(array, lb, ub);

		quicksort(array, lb, loc - 1);
		quicksort(array, loc + 1, ub);
	}
}

/**
* quick_sort - calls quick sort on an array
*@array: array to be sorted
*@size: size of the array
*Return: void
*/

void quick_sort(int *array, size_t size)
{

	if (!array || !size)
		return;

	quicksort(array, 0, size - 1);
}
