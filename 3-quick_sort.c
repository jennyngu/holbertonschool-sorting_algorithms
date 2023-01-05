#include "sort.h"

/**
 *swap_elements - swaps two elements
 *@x: an element to be swapped with y
 *@y: an element to be swapped with x
 */

void swap_elements(int *x, int *y)
{
	int value_holder;

	value_holder = *x;
	*x = *y;
	*y = value_holder;
}

/**
 *partition - implementation of the Lamuto partition scheme
 *@array: pointer to array
 *@low: lowest index of array
 *@high: highest index of array
 *@size: size of array
 *Return: parition position
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot_point, i, j;

	if (array == NULL)
	{
		return (-1);
	}
	pivot_point = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot_point)
		{
			i = i + 1;
			if (i != j)
			{
				swap_elements(&array[i], &array[j]);
				print_array(array, size);
			}
		}
		j = j + 1;
	}
	if (array[high] < array[i + 1])
	{
		swap_elements(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 *quickSort - recursive sorting using Lamuto partition scheme
 *@array: pointer to array
 *@low: lowest index of array
 *@high: highest index of array
 *@size: size of array
 */

void quickSort(int *array, int low, int high, size_t size)
{
	int partition_point;

	if (array == NULL)
	{
		return;
	}
	if (low < high)
	{
		partition_point = partition(array, low, high, size);
		quickSort(array, low, partition_point - 1, size);
		quickSort(array, partition_point + 1, high, size);
	}
}

/**
 *quick_sort - sorts an array by calling a recursive function
 *that uses the Lamuto parition scheme
 *@array: pointer to array
 *@size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
	{
		return;
	}
	quickSort(array, 0, size - 1, size);
}
