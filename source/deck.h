/*
 *  deck.h
 *  Created on: Apr 2021
 *  Author: Nander Carmo
 *  Version: 1.0
 *  License: MIT
 * 	Based on the Bill Weinman code taken from https://bw.org/cpp/
 */

#ifndef MY_DECK_H
#define MY_DECK_H

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "cards.h"
#include "exception.h"

namespace My {

	static constexpr int DEBUG = 0;
	static constexpr int DECK_MAXIMUM = 10;

	enum Print_e: uint8_t { 

		DRAW = 1,
		RANK_SUIT,
		TEXT
	};

	typedef std::vector<const Card_t *> Deck_t;

	class Deck {

		Deck_t * _deck;
		Deck_t * _hand;		
		Print_e _printMode;
		int _numberOfDecks;

		const char * _printCardDraw(const Card_t *, uint8_t);
		const char * _printCardRankSuit(const Card_t *, uint8_t);
		const char * _printCardText(const Card_t *, uint8_t);
		const char * _printCardRaw(const Card_t *, uint8_t);

	public:

		Deck();
		~Deck();

		void newDeck(int);
		void shuffle();
		void dealCards(int);
		void discardCard(int);

		int getNumberOfDecks();
		int getDeckSize();
		int getRemainingCards();
		int getHandSize();
		const Deck_t * getDeck();
		const Deck_t * getHand();

		void setPrintMode(Print_e);
		
		void printDeck();
		void printHand();
		void printRaw();
	};
}

#endif