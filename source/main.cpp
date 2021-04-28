#include <cerrno>

#include "deck.h"

int main() {

	printf("Default deck size: %i\n", My::DEFAULT_DECK_SIZE);

	My::Deck deck;

	deck.newDeck(1);

    return errno; 
}