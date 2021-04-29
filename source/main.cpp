#include <cerrno>

#include "deck.h"

int main() {

	My::Deck deck;

	try {

		deck.newDeck(1);
		deck.shuffle();
		deck.printRaw();

	} catch(My::Exception & e) {

		std::cout << e.what() << std::endl;
	}

    return errno; 
}