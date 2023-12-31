#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size, int exp)
{
	void exp;
	int *count_array, *sorted_array;
	int i, max_value = 0;

	if (size < 2)
		return;

	/* Find the max value in the array */
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Allocate memory for the count array */
	count_array = malloc(sizeof(int) * (max_value + 1));
	if (count_array == NULL)
		return;

	/* Count the occurrences of each value in the array */
	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	/* Modify the count array to store the actual position of each value */
	for (i = 1; i <= max_value; i++)
		count_array[i] += count_array[i - 1];

	/* Allocate memory for the sorted array */
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}

	/* Build the sorted array */
	for (i = (int)size - 1; i >= 0; i--)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	/* Copy the sorted array back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	/* Print the count array */
	printf("%d", count_array[0]);
	for (i = 1; i <= max_value; i++)
		printf(", %d", count_array[i]);
	printf("\n");

	/* Free memory */
	free(count_array);
	free(sorted_array);
}
