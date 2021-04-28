/*
 *  deck.cpp
 *  Created on: Apr 2021
 *  Author: Nander Carmo
 *  Version: 1.0
 *  License: MIT
 */

#include "deck.h"

using namespace My;

Deck::Deck() { 
	if(DEBUG) printf("Deck::Deck\n"); 
};

Deck::~Deck() {

	if(DEBUG) printf("Deck::~Deck\n");

	if(_deck) delete _deck;
	if(_hand) delete _hand;

	_numberOfDecks = 0;	
}

void Deck::newDeck(int decks) {

	if(DEBUG) printf("Deck::newDeck\n");

	if(decks > 0 && decks <= DECK_MAXIMUM) {

		_deck = new Deck_t;
		//_deck->reserve(decks * DEFAULT_DECK_SIZE);

		for (int deck = 0; deck < decks; ++deck) {
			
			for(int card = 0; card < DEFAULT_DECK_SIZE; ++card) {

				_deck->push_back(&DEFAULT_DECK[card]);
			}
		}
		
		_hand = new Deck_t;

		_numberOfDecks = decks;

	} else throw EXECPTION_INVALID_DECK_NUMBER;
}

void Deck::shuffle() {

	if(DEBUG) printf("Deck::shuffle\n");
}

void Deck::dealCards(int cards = 1) {

	if(DEBUG) printf("Deck::dealCards\n");
}

void Deck::discardCard(int index = 0) {

	if(DEBUG) printf("Deck::discardCard\n");
}

int Deck::getNumberOfDecks() { 

	if(DEBUG) printf("Deck::getNumberOfDecks\n");
	return _numberOfDecks; 
}

int Deck::getDeckSize() { 

	if(DEBUG) printf("Deck::getDeckSize\n");
	return _numberOfDecks * DEFAULT_DECK_SIZE; 
}


int Deck::getRemainingCards() {

	if(DEBUG) printf("Deck::getRemainingCards\n");
	return _deck->size(); 
}

int Deck::getHandSize() {

	if(DEBUG) printf("Deck::getHandSize\n");
	return _hand->size(); 
}

const Deck_t * Deck::getDeck() { 

	if(DEBUG) printf("Deck::getDeck\n");
	return _deck; 
}

const Deck_t * Deck::getHand() { 

	if(DEBUG) printf("Deck::getHand\n");
	return _hand; 
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
	
	if(_deck != nullptr) {

		char formatedString[100];
		std::string print = "\nDECK:\n\n";

		for(auto card: *_deck) {

			sprintf(
				formatedString,
				"Card: { rank: %s, suit: { name: \"%s\", symbol: %s }, draw: %s }\n",
				card->rank, 
				SUITS[card->suit].name, 
				SUITS[card->suit].symbol,
				card->draw
			);

			print += formatedString;
		}

		if(!_hand->empty()) {

			print += "\nHAND:\n\n";

			for(auto card: *_hand) {

				sprintf(
					formatedString,
					"Card: { rank: %s, suit: { name: \"%s\", symbol: %s }, draw: %s }\n",
					card->rank, 
					SUITS[card->suit].name, 
					SUITS[card->suit].symbol,
					card->draw
				);

				print += formatedString;
			}

			print += "\n";

		} else print += "\nHAND: The hand is empty!\n\n";

		print += "Number of decks: ";
		print += std::to_string(getNumberOfDecks());
		print += "\nDeck size: ";
		print += std::to_string(getDeckSize());
		print += " cards\nRemaining cards: ";
		print += std::to_string(getRemainingCards());
		print += " cards\nHand size: ";
		print += std::to_string(getHandSize());
		print += " cards\n\n";

		std::cout << print;
		
		return print;
	
	} else {
		
		throw EXCEPTION_DECK_NOT_CREATED;

		return std::string(EXCEPTION_DECK_NOT_CREATED.what());
	}
}

// Non-member function

std::ostream & operator<<(std::ostream & stream, const Deck & deck) {

	return stream << "operator<<\n";
}


