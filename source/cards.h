/*
 *  cards.h
 *  Created on: Apr 2021
 *  Author: Nander Carmo
 *  Version: 1.0
 *  License: MIT
 * 	Based on the Bill Weinman code taken from https://bw.org/cpp/
 */

#ifndef MY_CARDS_H
#define MY_CARDS_H

#include <cstdint>

namespace My {

	enum Suits_e: uint8_t { 
		
		SPADES = 0, 
		HEARTS,
		DIAMONDS,
		CLUBS 
	};
 
	enum Rank_e: uint8_t { 
		
		ACE = 0, 
		TWO, 
		THREE, 
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING 
	}; 

	struct Card_t {

		const Suits_e suit;
		const Rank_e rank;
		const char * const draw;
	};

	struct Suit_t {

		const char * name;
		const char * symbol;
	};

	struct Rank_t {

		const char * name;
		const char * symbol;
	};

	static const Suit_t SUITS[] = { 

		{ "Spades", "♠" }, 
		{ "Hearts", "♥" }, 
		{ "Diamonds", "♦" }, 
		{ "Clubs", "♣" }
	};

	static const Rank_t RANKS[] = { 

		{ "Ace", "A" },
		{ "Two", "2" },
		{ "Three", "3" },
		{ "Four", "4" },
		{ "Five", "5" },
		{ "Six", "6" },
		{ "Seven", "7" },
		{ "Eight", "8" },
		{ "Nine", "9" },
		{ "Ten", "10" },
		{ "Jack", "J" },
		{ "Queen", "Q" }, 
		{ "King", "K" } 
	};

	static const Card_t DEFAULT_DECK[] {
		
		{ SPADES, ACE, "🂡" }, { HEARTS, ACE, "🂱" }, { DIAMONDS, ACE, "🃁" }, { CLUBS, ACE, "🃑" },
		{ SPADES, TWO, "🂢" }, { HEARTS, TWO, "🂲" }, { DIAMONDS, TWO, "🃂" }, { CLUBS, TWO, "🃒" },
		{ SPADES, THREE, "🂣" }, { HEARTS, THREE, "🂳" }, { DIAMONDS, THREE, "🃃" }, { CLUBS, THREE, "🃓" },
		{ SPADES, FOUR, "🂤" }, { HEARTS, FOUR, "🂴" }, { DIAMONDS, FOUR, "🃄" }, { CLUBS, FOUR, "🃔" },
		{ SPADES, FIVE, "🂥" }, { HEARTS, FIVE, "🂵" }, { DIAMONDS, FIVE, "🃅" }, { CLUBS, FIVE, "🃕" },
		{ SPADES, SIX, "🂦" }, { HEARTS, SIX, "🂶" }, { DIAMONDS, SIX, "🃆" }, { CLUBS, SIX, "🃖" },
		{ SPADES, SEVEN, "🂧" }, { HEARTS, SEVEN, "🂷" }, { DIAMONDS, SEVEN, "🃇" }, { CLUBS, SEVEN, "🃗" },
		{ SPADES, EIGHT, "🂨" }, { HEARTS, EIGHT, "🂸" }, { DIAMONDS, EIGHT, "🃈" }, { CLUBS, EIGHT, "🃘" },
		{ SPADES, NINE, "🂩" }, { HEARTS, NINE, "🂹" }, { DIAMONDS, NINE, "🃉" }, { CLUBS, NINE, "🃙" },
		{ SPADES, TEN, "🂪" }, { HEARTS, TEN, "🂺" }, { DIAMONDS, TEN, "🃊" }, { CLUBS, TEN, "🃚" },
		{ SPADES, JACK, "🂫" }, { HEARTS, JACK, "🂻" }, { DIAMONDS, JACK, "🃋" }, { CLUBS, JACK, "🃛" },
		{ SPADES, QUEEN, "🂭" }, { HEARTS, QUEEN, "🂽" }, { DIAMONDS, QUEEN, "🃍" }, { CLUBS, QUEEN, "🃝" },
		{ SPADES, KING, "🂮" }, { HEARTS, KING, "🂾" }, { DIAMONDS, KING, "🃎" }, { CLUBS, KING, "🃞" }
	};

	static constexpr int DEFAULT_DECK_SIZE = (int) sizeof(DEFAULT_DECK) / sizeof(Card_t);
}

#endif