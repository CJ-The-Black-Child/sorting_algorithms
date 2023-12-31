#ifndef SORT_H
#define SORT_H

#include <stddef.h>

#include "deck.h"

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer t the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void lomuto_sort(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void counting_sort(int *array, size_t size, int exp);
void merge_sort(int *array, size_t size);
void merge(int *array, int *left, int left_size, int *right, int right_size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void swap(int *array, int i, int j);
void bitonic_merge(int *array, int low, int count, int dir);
void bitonic_sort_recursive(int *array, int low, int count, int dir);
void bitonic_sort(int *array, size_t size);
void array_swap(int *a, int *b);
int partition_hoare(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);
int compare_cards(const void *card1, const void *card2);

#endif /* SORT_H*/
