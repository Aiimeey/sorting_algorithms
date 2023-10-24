#include "sort.h"
/**
 * swap - Swaps two integer values
 * @x: Pointer to the first integer
 * @y: Pointer to the second integer
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * lomuto - Lomuto partition scheme for Quick Sort
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot element
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high ; j++)
	{
		if (array[j] < pivot)
		{

			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sort_recursive - Recursive function to perform Quick Sort
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integers using Quick Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
