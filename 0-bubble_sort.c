#include "sort.h"
#include <stdio.h>
/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int x, check;
	size_t i = 0;

	if (!array)
		return;
	do {
		check = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				x = array[i];
				array[i] = array[i + 1];
				array[i + 1] = x;
				print_array(array, size);
				check = 1;
			}
		}
	} while (check);

}
