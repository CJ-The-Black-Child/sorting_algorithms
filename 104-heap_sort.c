#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Helper function to perform the sit-down operation
 * in the Heap sort algorithm.
 *
 * @array: The array to be sorted.
 * @start: The start index of the subarray to sift down.
 * @end: The end index of the subarray to sift down.
 * @size: The size of the array.
 */

void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	int temp;

	while (2 * root + 1 <= end)
	{
		size_t child = 2 * root + 1;
		size_t swap = root;

		if (child < end && array[child] < array[child + 1])
			child++;

		if (array[swap] < array[child])
			swap = child;

		if (swap == root)
			return;

		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);

		root = swap;
	}
}
/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap
 * sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, i, size - 1, size);

	/* Heap sort */
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
