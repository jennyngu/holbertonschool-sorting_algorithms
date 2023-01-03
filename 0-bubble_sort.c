#include "sort.h"

/**
 *bubble_sort - sorts array of ints in ascending order using Bubble sort algorithm
 *@array: pointer to start of array
 *@size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t temp_value;
	size_t sorted;

	if (array == NULL)
	{
		return;
	}
	while (sorted != 1)
	{
		i = 0;
		sorted = 1;
		while (i < size - 1)
		{
			if (array[i] >= array[i + 1])
			{
				sorted = 0;
				temp_value = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp_value;
				print_array(array, size);
			}
			i = i + 1;
		}
	}
}
