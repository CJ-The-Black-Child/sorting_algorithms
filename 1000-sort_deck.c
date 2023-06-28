#include "deck.h"
#include "sort.h"
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Compare 2 cards based on their values and kinds.
 * @card1: Pointer to the 1st card.
 * @card2: Pointer to the 2nd card.
 *
 * Return: Negative value if card1 is less than card2,
 * Positive value if card1 is greater than card2,
 * Zero if card1 is equal to card2.
 */

int compare_cards(const void *card1, const void *card2)
{
	const card_t *c1 = *(const card_t **)card1;
	const card_t *c2 = *(const card_t **)card2;

	int value_comparison = strcmp(c1->value, c2->value);

	if (value_comparison != 0)
		return (value_comparison);

	if (c1->kind < c2->kind)
		return (-1);
	else if (c1->kind > c2->kind)
		return (1);
	else
		return (0);

}

/**
 * sort_deck - Sorts a deck of cards in ascending order.
 * @deck: Pointer to the head of the deck.
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *temp;
	card_t *cards[52];
	int i;

	if (deck == NULL || *deck == NULL)
		return;

	current = *deck;
	i = 0;

	while (current != NULL)
	{
		cards[i++] = (card_t *)current->card;
		temp = current;
		current = current->next;
		free(temp);
	}

	qsort(cards, 52, sizeof(card_t *), compare_cards);

	*deck = NULL;

	for (i = 0; i < 52; i++)
	{
		current = malloc(sizeof(deck_node_t));
		if (current == NULL)
			return;

		current->card = cards[i];
		current->prev = NULL;
		current->next = *deck;

		if (*deck != NULL)
			(*deck)->prev = current;

		*deck = current;
	}
}
