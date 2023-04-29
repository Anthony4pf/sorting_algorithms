#include "sort.h"


/**
*swap - sawp two elements of an array
*@array: array
*@size: size of the array
*@a: first element
*@b: second element
*Return: void
*/

void swap(int *array, size_t size, int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	print_array((const int *)array, size);
}

/**
*lomuto_partition - partition an array around a pivot
*@array: array to be partitioned
*@size: size of the array
*@low: lowerbound of the array
*@high: upperbound of the arrat
*Return: position of the pivot
*/

size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int pivot, current_index;
	int i;

	pivot = array[high];
	current_index = low - 1;

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			current_index++;
			swap(array, size, &array[current_index], &array[i]);
		}
	}
	swap(array, size, &array[current_index + 1], &array[high]);
	return (current_index + 1);
}

/**
*quicksort - sort an array using quick sort
*@array: array to be sorted
*@size: size of the array
*@low: lowerbound of the array
*@high: upperbound of the array
*Return: void
*/

void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	size_t pos;

	if (low < high)
	{
		pos = lomuto_partition(array, size, low, high);

		quicksort(array, size, low, pos - 1);
		quicksort(array, size, pos + 1, high);
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

	quicksort(array, size, 0, size - 1);
}
