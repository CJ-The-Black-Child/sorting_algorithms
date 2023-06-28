#include "sort.h"
#include <stdio.h>

/**
 * array_swap - swaps 2 elements in an array
 * @a: First element
 * @b: Second element
 */

void array_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition_hoare - Partitions the array using the Hoare scheme.
 * @array: Array to be sorted.
 * @low: Starting the index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array.
 *
 * Return: Index of the pivot element.
 */

int partition_hoare(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		array_swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quicksort_hoare - Recursive function to perform quicksort using Hoare scheme
 * @array: Array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 */

void quicksort_hoare(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition_hoare(array, low, high, size);
		quicksort_hoare(array, low, pivot - 1, size);
		quicksort_hoare(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 * Quick Sort (Hoare Scheme)
 * @array: Array to be sorted.
 * @size: The Size of the array.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size);
}
