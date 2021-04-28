/*
 *  deck.cpp
 *  Created on: Apr 2021
 *  Author: Nander Carmo
 *  Version: 1.0
 *  License: MIT
 */

#include "deck.h"

using namespace My;

Deck::~Deck() {

	if(DEBUG) printf("Deck::~Deck\n");

	if(_deck) delete _deck;
	if(_hand) delete _hand;

	_remainingCards = DEFAULT_DECK_SIZE;
	_deckSize = DEFAULT_DECK_SIZE;
	_index = 0;	
}

int Deck::getRemainingCards() { 

	if(DEBUG) printf("Deck::getRemainingCards\n");


	return _remainingCards; 
}

int Deck::getNumberOfDecks() { 

	if(DEBUG) printf("Deck::getNumberOfDecks\n");
	return _deckSize / DEFAULT_DECK_SIZE; 
}

int Deck::getDeckSize() { 

	if(DEBUG) printf("Deck::getDeckSize\n");
	return _deckSize; 
}

const Deck_t * Deck::getDeck() { 

	if(DEBUG) printf("Deck::getDeck\n");
	return _deck; 
}

const Deck_t * Deck::getHand() { 

	if(DEBUG) printf("Deck::getHand\n");
	return _hand; 
}

void Deck::shuffle() {

	if(DEBUG) printf("Deck::shuffle\n");


}

void Deck::newDeck(int decks = 1) {

	if(DEBUG) printf("Deck::newDeck\n");

	_deck = new Deck_t(DEFAULT_DECK, DEFAULT_DECK + DEFAULT_DECK_SIZE);

	printRaw();
}

void Deck::dealCards(int cards = 1) {

	if(DEBUG) printf("Deck::dealCards\n");
}

void Deck::discardCard(int index = 0) {

	if(DEBUG) printf("Deck::discardCard\n");
}

		
void Deck::printDeckText() {

	if(DEBUG) printf("Deck::printDeckText\n");
}

void Deck::printDeckDraw() {

	if(DEBUG) printf("Deck::printDeckDraw\n");
}

void Deck::printHandText() {

	if(DEBUG) printf("Deck::printHandText\n");
}

void Deck::printHandDraw() {

	if(DEBUG) printf("Deck::printHandDraw\n");
}

std::string Deck::printRaw() {

	if(DEBUG) printf("Deck::printRaw\n");
	
	char formatedString[100];
	std::string print = "";

	std::cout << std::endl;

	for(auto card: *_deck) {

		sprintf(
			formatedString,
			"Card: { rank: %s, suit: { name: \"%s\", symbol: %s }, draw: %s }\n",
			card.rank, 
			SUITS[card.suit].name, 
			SUITS[card.suit].symbol,
			card.draw
		);

		print += formatedString;
	}

	std::cout << print << std::endl;
	
	return print;
}

// Nom-member function

std::ostream & operator<<(std::ostream & stream, const Deck & deck) {

	return stream << "operator<<\n";
}


