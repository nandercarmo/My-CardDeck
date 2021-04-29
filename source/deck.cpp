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

	if(_deck) {
		
		_deck->clear();	
		delete _deck;
	}
	
	if(_hand) {

		_hand->clear();
		delete _hand;
	}

	_numberOfDecks = 0;	
}

void Deck::newDeck(int decks) {

	if(DEBUG) printf("Deck::newDeck(%i)\n", decks);

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

	if(_deck) {

		srand((unsigned) time(nullptr));
		rand();

		for(size_t i = 0; i < _deck->size(); ++i) {

			int indexToChange = rand() % _deck->size();

			const Card_t * auxCard = _deck->at(i);

			_deck->at(i) = _deck->at(indexToChange);
			_deck->at(indexToChange) = auxCard;
		}

	} else throw EXCEPTION_DECK_NOT_CREATED;
}

void Deck::dealCards(int cards) {

	if(DEBUG) printf("Deck::dealCards(%i)\n", cards);

	if(_deck) {

		if(_deck->empty()) printf("\nDeck is empty! There's no card to deal!\n\n");
		else {

			if(cards > 0 && cards < (int) _deck->size() + 1) {

				for (int i = 0; i < cards; i++)	{
					
					const Card_t * dealCard = _deck->back();

					_deck->pop_back();
					_hand->push_back(dealCard);
				}

			} else throw EXECPTION_INVALID_DEAL_CARDS_NUMBER;
		}

	} else throw EXCEPTION_DECK_NOT_CREATED;
}

void Deck::discardCard(int index) {

	if(DEBUG) printf("Deck::discardCard(%i)\n", index);

	if(_deck) {

		if(_hand->empty()) printf("\nHand is empty! There's no card to discard!\n\n");
		else {

			if(index >= 0 && index < (int) _hand->size()) {

				printf(
					"\nDISCARDED CARD: { rank: %s, suit: { name: \"%s\", symbol: %s }, draw: %s }\n\n",
					_hand->at(index)->rank, 
					SUITS[_hand->at(index)->suit].name, 
					SUITS[_hand->at(index)->suit].symbol,
					_hand->at(index)->draw
				);

				_hand->erase(_hand->begin() + index);

			} else throw EXECPTION_INVALID_CARD_TO_DISCARD;
		}

	} else throw EXCEPTION_DECK_NOT_CREATED;
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
		std::string print = "";
		
		if(_deck->empty()) print += "\nDECK: The deck is empty!\n";
		else {

			print += "\nDECK:\n\n";

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
		}

		if(_hand->empty()) print += "\nHAND: The hand is empty!\n\n";
		else {

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
		} 

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