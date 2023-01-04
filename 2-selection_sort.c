#include "sort.h"

/**
 *selection_sort - sorts an array in ascending order
 *using Selection sort algorithm
 *@array: pointer to start of array
 *@size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, num_holder;

	if (array == NULL)
	{
		return;
	}
	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
			j = j + 1;
		}
		if (min != i)
		{
			num_holder = array[min];
			array[min] = array[i];
			array[i] = num_holder;
			print_array(array, size);
		}
		i = i + 1;
	}
}
