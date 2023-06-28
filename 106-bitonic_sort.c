#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap - Swaps two elements in an array.
 * @array: The array containing the elements.
 * @i: The index of the first element to swap.
 * @j: The index of the second element to swap.
 */

void swap(int *array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * bitonic_merge - Merges two halves of a bitonic sequence
 * in the specified direction.
 * @array: The array containing the bitonic sequence.
 * @low: The starting index of the first half.
 * @count: The number of elements to merge.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */

void bitonic_merge(int *array, int low, int count, int dir)
{
	if (count > 1)
	{
		int k = count / 2;
		int i;

		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
				swap(array, i, i + k);
		}

		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence
 * in the specified direction.
 * @array: The array containing the bitonic sequence.
 * @low: The starting index of the sequence.
 * @count: The number of elements in the sequence
 * @dir: The sorting direction ( 1 for ascending, 0 for descending)
 */

void bitonic_sort_recursive(int *array, int low, int count, int dir)
{
	if (count > 1)
	{
		int k = count / 2;

		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);

	printf("Merging [%lu/%lu] (UP):\n", size, size);
	print_array(array, size);
}
