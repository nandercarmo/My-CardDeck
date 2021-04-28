/*
 *  deck.h
 *  Created on: Apr 2021
 *  Author: Nander Carmo
 *  Version: 1.0
 *  License: MIT
 */

#ifndef MY_DECK_H
#define MY_DECK_H

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

#include "cards.h"
#include "exception.h"

namespace My {

	static constexpr int DEBUG = 1;
	static constexpr int DECK_MAXIMUM = 10;

	typedef std::vector<const Card_t *> Deck_t;

	class Deck {

		Deck_t * _deck = nullptr;
		Deck_t * _hand = nullptr;
		int _numberOfDecks = 0;

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
		
		void printDeckText();
		void printDeckDraw();
		void printHandText();
		void printHandDraw();
		std::string printRaw();
	};

	std::ostream & operator<<(std::ostream & stream, const Deck & deck);
}

#endif