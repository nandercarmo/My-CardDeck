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
#include <iostream>

#include "cards.h"

namespace My {

	static constexpr int DEFAULT_DECK_SIZE = 52;
	static constexpr int DECK_MAXIMUM = 10;

	typedef std::vector<Card_t> Deck_t;

	class Deck {

		Deck_t * _deck;
		Deck_t * _hand;
		int _deckSize;
		int _remainingCards;
		int _index;

	public:

		Deck(int size = 1) : _deckSize(size) {};
		~Deck();

		void start();
		void shuffle();
		
		void printDeckText();
		void printDeckDraw();
		void printHandText();
		void printHandDraw();

		int getRemainingCards() { return _remainingCards; };
		int getNumberOfDecks() { return _deckSize / DEFAULT_DECK_SIZE; };

		void takeCards(int cards = 1);

		Deck & operator= (const Deck & deck);

		const Deck_t * getDeck() { return _deck; };
		const Deck_t * getHand() { return _hand; };
	};

	std::ostream & operator<< (std::ostream stream, const Deck & deck);
}

#endif