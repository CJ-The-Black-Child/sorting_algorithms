#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm with Lomuto partition scheme.
 * @array: Pointer to the array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, 0, size - 1, size);
}

/**
 * lomuto_sort - performs quicksort using lomuto partition scheme
 * @array: Pointer to the array to be sorted
 * @low: starting index of the partition to be sorted.
 * @high: ending index of the partition to be sorted.
 * @size: size of the array
 */

void lomuto_sort(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high);
		print_array(array, high - low + 1);
		lomuto_sort(array, low, partition - 1, size);
		lomuto_sort(array, partition + 1, high, size);
	}
}

/**
 * lomuto_partition - performs partition using Lomuto scheme
 * @array: pointer to the array to be partitioned
 * @low: startimng index of the partition
 * @high: ending index of the partition
 *
 * Return: index of the pivot element
 */

int lomuto_partition(int *array, int low, int high)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, (size_t)(high - low + 1));
			}
			i++;
		}
	}

	if (array[i] != array[high])
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, (size_t)(high - low + 1));
	}

	return (i);
}
