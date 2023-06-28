#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - performs counting sort based on the significant digit.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current significant digit to consider.
 */

void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
		return;

	/* Count occurrences of digits */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	/* Calculate cumulative count */
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	/* Copy the elements to output array, respecting the order */
	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] /exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the output array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	print_array(array, size);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix
 * sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void radix_sort(int *array, size_t size)
{
	int max = 0;
	size_t i;
	int exp;

	if (array ==  NULL || size < 2)
		return;

	/* Find the maximum number to determine the number of digits */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Perform counting sort for every digit */
	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort(array, size, exp);
}
