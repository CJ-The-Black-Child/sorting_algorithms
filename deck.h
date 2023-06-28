#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Enumeration of card kinds.
 * @SPADE: Spade kind.
 * @HEART: Heart kind.
 * @CLUB: Club kind.
 * @DIAMOND: Diamond kind.
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Structure representing a playing card.
 * @value: Value of the card.
 * @kind: Kind of the card.
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Structure representing a node in a deck of cards.
 * @card: Pointer to the card.
 * @prev: Poiter to the previous node.
 * @next: Pointer to the next node.
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Function prototype */

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
