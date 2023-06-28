#include "sort.h"
<<<<<<< HEAD
=======
#include <stdlib.h>
>>>>>>> 10d40db9e700e1e4c119bd45e7b2c4f900c74691
#include <stdio.h>

/**
 * merge - Merges 2 sub-arrays into a sorted array.
 *
 * @array: The original array.
 * @left: The left  sub-array.
 * @left_size: Number of elements in the lef sub -array.
 * @right: The right sub-array.
 * @right_size: Number of elements in the right sub-array.
 */

void merge(int *array, int *left, int left_size, int *right, int right_size)
{
	int i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * Merge sort algorithm.
 *
 * @array: The array to be printed.
 * @size: Number of elements in @array.
 */

void merge_sort(int *array, size_t size)
{
	int mid, *left, *right, i, j, k, left_size, right_size;

	if (size <= 1)
		return;

	mid = size / 2;
	left = array;

	merge_sort(left, mid);
	merge_sort(left + mid, size - mid);

	/* Merge the sorted sub-arrays */
	left_size = mid;
	right_size = size - mid;
<<<<<<< HEAD
	right[right_size];
=======
	right= malloc(right_size * sizeof(int));
>>>>>>> 10d40db9e700e1e4c119bd45e7b2c4f900c74691



	for (i = 0; i < right_size; i++)
		right[i] = left[mid + i];

	i = 0;
	j = 0;
	k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];
}
