#include "sort.h"
/**
 * selection_sort - Sort an array of integer using the Selection Sort algorithm
 *
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int long i, j;
	int x, y, s, check;


	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		check = 0;
		for (j = i; j < size; j++)
		{
			x = i;

			if (array[i] > array[j])
			{
				if (check == 1)
					if (array[y] < array[j])
						continue;
				check = 1;
				x = i;
				y = j;
			}
		}
		if (check == 1)
		{
			s = array[x];
			array[x] = array[y];
			array[y] = s;
			print_array(array, size);
		}
	}
}


