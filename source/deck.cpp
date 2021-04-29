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

	_deck = nullptr;
	_hand = nullptr;
	_printMode = DRAW;
	_numberOfDecks = 0; 
}

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
		_deck->reserve(decks * DEFAULT_DECK_SIZE);

		for (int deck = 0; deck < decks; ++deck) {
			
			for(int card = 0; card < DEFAULT_DECK_SIZE; ++card) {

				_deck->push_back(&DEFAULT_DECK[card]);
			}
		}
		
		_hand = new Deck_t;

		_numberOfDecks = decks;

		printf("Created %i %s\n", decks, decks == 1 ? "deck" : "decks");

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

		printf("Deck shuffled\n");

	} else throw EXCEPTION_DECK_NOT_CREATED;
}

void Deck::dealCards(int cards) {

	if(DEBUG) printf("Deck::dealCards(%i)\n", cards);

	if(_deck) {

		if(_deck->empty()) printf("Deal cards:\n\n\tDeck is empty! There's no card to deal!\n\n");
		else {

			if(cards > 0 && cards < (int) _deck->size() + 1) {

				printf("Deal %i %s:\n\n", cards, cards == 1 ? "card" : "cards");

				int i;

				for (i = 0; i < cards; i++)	{
					
					const Card_t * dealCard = _deck->back();

					_deck->pop_back();
					_hand->push_back(dealCard);

					switch (_printMode) {
			
						case DRAW:
							
							printf("%s%s", _printCardDraw(dealCard), (i + 1 % 13) ? "" : "\n\n");
							break;

						case RANK_SUIT:

							printf("%s%s", _printCardRankSuit(dealCard), (i + 1 % 13) ? "" : "\n\n");
							break;

						case TEXT:

							printf("%s", _printCardText(dealCard));
							break;
						
						default: break;
					}
				}

				if(_printMode == DRAW || _printMode == RANK_SUIT) printf(i % 13 ? "\n\n" : "\n");

			} else throw EXECPTION_INVALID_DEAL_CARDS_NUMBER;
		}

	} else throw EXCEPTION_DECK_NOT_CREATED;
}

void Deck::discardCard(int index) {

	if(DEBUG) printf("Deck::discardCard(%i)\n", index);

	if(_deck) {

		printf("Discarded card:\n\n");

		if(_hand->empty()) printf("Hand is empty! There's no card to discard!\n\n");
		else {

			if(index >= 0 && index < (int) _hand->size()) {

				switch (_printMode) {
			
					case DRAW:
						
						printf("%s\n\n", _printCardDraw(_hand->at(index)));
						break;

					case RANK_SUIT:

						printf("%s\n\n", _printCardRankSuit(_hand->at(index)));
						break;

					case TEXT:

						printf("%s", _printCardText(_hand->at(index)));
						break;
					
					default: break;
				}

				_hand->erase(_hand->begin() + index);

			} else throw EXECPTION_INVALID_CARD_TO_DISCARD;
		}

	} else throw EXCEPTION_DECK_NOT_CREATED;
}

int Deck::getNumberOfDecks() { 

	if(DEBUG) printf("Deck::getNumberOfDecks\n");

	if(_deck) {

		printf("Number of decks: %i %s\n", _numberOfDecks, (_numberOfDecks == 1) ? "deck" : "decks");
		return _numberOfDecks; 

	} else throw EXCEPTION_DECK_NOT_CREATED;
}

int Deck::getDeckSize() { 

	if(DEBUG) printf("Deck::getDeckSize\n");

	if(_deck) {

		printf("Start deck size: %i cards\n", _numberOfDecks * DEFAULT_DECK_SIZE);
		return _numberOfDecks * DEFAULT_DECK_SIZE; 

	} else throw EXCEPTION_DECK_NOT_CREATED;
}


int Deck::getRemainingCards() {

	if(DEBUG) printf("Deck::getRemainingCards\n");

	if(_deck) {

		printf("Remaining cards: %i %s\n", (int) _deck->size(), (_deck->size() == 1) ? "card" : "cards");
		return _deck->size(); 

	} else throw EXCEPTION_DECK_NOT_CREATED;
}

int Deck::getHandSize() {

	if(DEBUG) printf("Deck::getHandSize\n");

	if(_deck) {

		printf("Hand size: %i %s\n", (int) _hand->size(), (_hand->size() == 1) ? "card" : "cards");
		return _hand->size(); 

	} else throw EXCEPTION_DECK_NOT_CREATED;
}

const Deck_t * Deck::getDeck() { 

	if(DEBUG) printf("Deck::getDeck\n");

	if(_deck) {

		printf("Get deck\n");
		return _deck; 

	} else throw EXCEPTION_DECK_NOT_CREATED;
}

const Deck_t * Deck::getHand() { 

	if(DEBUG) printf("Deck::getHand\n");

	if(_deck) {

		printf("Get hand\n");
		return _hand; 

	} else throw EXCEPTION_DECK_NOT_CREATED;
}

void Deck::setPrintMode(Print_e printMode) {

	if(DEBUG) printf("Deck::setPrintMode\n");
	_printMode = printMode;

	printf("Set print mode to: ");

	switch (_printMode) {
			
		case DRAW: printf("Draw Mode\n"); break;
		case RANK_SUIT: printf("Rank and Suit Mode\n"); break;
		case TEXT: printf("Text Mode\n"); break;
		default: break;
	}
}

void Deck::printDeck() {

	if(DEBUG) printf("Deck::printDeck\n");

	if(_deck) {

		uint8_t i = 0;

		printf("Deck:\n\n");

		switch (_printMode) {
			
			case DRAW:

				for(auto card: *_deck) printf("%s%s", _printCardDraw(card), (++i % 13) ? "" : "\n\n");
				printf(i % 13 ? "\n\n" : "\n");
				break;

			case RANK_SUIT:

				for(auto card: *_deck) printf("%s%s", _printCardRankSuit(card), (++i % 13) ? "" : "\n\n");
				printf(i % 13 ? "\n\n" : "\n");
				break;

			case TEXT:

				for(auto card: *_deck) printf("%s", _printCardText(card));
				break;
			
			default: break;
		}

	} else throw EXCEPTION_DECK_NOT_CREATED;
}

void Deck::printHand() {

	if(DEBUG) printf("Deck::printHand\n");
}

void Deck::printRaw() {

	if(DEBUG) printf("Deck::printRaw\n");
	
	if(_deck != nullptr) {

		std::string print = "Deck:\n\n";
		
		if(_deck->empty()) print += "\tThe deck is empty!\n\n";
		else {

			for(auto card: *_deck) print += _printCardRaw(card);
			print += "\n";
		}

		print += "Hand:\n\n";

		if(_hand->empty()) print += "\tThe hand is empty!\n\n";
		else {

			for(auto card: *_hand) print += _printCardRaw(card);
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
		print += " cards\n";

		std::cout << print;
			
	} else {
		
		throw EXCEPTION_DECK_NOT_CREATED;
	}
}

// Private Functions

const char * Deck::_printCardDraw(const Card_t * card){

	static char formattedString[20];

	sprintf(formattedString, "\t%s", card->draw);

	return formattedString;
}

const char * Deck::_printCardRankSuit(const Card_t * card){

	static char formattedString[20];

	sprintf(formattedString, "\t%s %s", RANKS[card->rank].symbol, SUITS[card->suit].symbol);

	return formattedString;
}

const char * Deck::_printCardText(const Card_t * card){

	static char formattedString[20];

	sprintf(formattedString, "\t%s of %s\n\n", RANKS[card->rank].name, SUITS[card->suit].name);

	return formattedString;
}

const char * Deck::_printCardRaw(const Card_t * card) {

	static char formattedString[100];

	sprintf(
		formattedString,
		"\tCard: { rank: { name: \"%s\", symbol: \"%s\" }, suit: { name: \"%s\", symbol: %s }, draw: %s }\n",
		RANKS[card->rank].name, 
		RANKS[card->rank].symbol, 
		SUITS[card->suit].name, 
		SUITS[card->suit].symbol,
		card->draw
	);

	return formattedString;
}
