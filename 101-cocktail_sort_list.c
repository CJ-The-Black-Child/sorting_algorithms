#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (start = *list; start->next != NULL; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;

		swapped = 0;
		for (; start->prev != NULL; start = start->prev)
		{
			if (start->prev->n > start->n)
			{
				swap_nodes(list, start->prev, start);
				print_list(*list);
				swapped = 1;
			}
		}
	}
}
/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the doubly linked list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped.
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;
	else
		(*list)->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node1->next != NULL)
		node1->next->prev = node1;
	else
		node1->prev->next = node1;

	if (node2->prev != NULL)
		node2->prev->next = node2;
	else
		if (node2->next != NULL)
		node2->next->prev = node2;
}
