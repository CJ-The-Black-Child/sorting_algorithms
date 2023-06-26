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

	quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - recursive function to perform quick sort
 * @array: Pointer to the array to be sorted
 * @low: starting index of the partition to be sorted.
 * @high: ending index of the partition to be sorted.
 */

void quicksort_recursive(int *array, int low, int high)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high);
		print_array(array, high - low + 1);
		quicksort_recursive(array, low, partition - 1);
		quicksort_recursive(array, partition + 1, high);
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
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, high - low + 1);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, high - low + 1);
	}

	return (i + 1);
}
