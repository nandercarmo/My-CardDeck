#include <cerrno>

#include "deck.h"

int main() {

	My::Deck deck;

	try {

		deck.setPrintMode(My::DRAW);
		deck.newDeck(1);
		deck.shuffle();
		//deck.printRaw();
		deck.dealCards(5);
		//deck.printRaw();
		deck.discardCard(0);
		deck.printRaw();
		deck.printDeck();


	} catch(My::Exception & e) {

		std::cout << e.what() << std::endl;
	}

    return errno; 
}