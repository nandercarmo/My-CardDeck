/*
 *  cards.h
 *  Created on: Apr 2021
 *  Author: Nander Carmo
 *  Version: 1.0
 *  License: MIT
 */

#ifndef MY_CARDS_H
#define MY_CARDS_H

#include <cstdint>

namespace My {

	enum SUITS_ENUM: uint8_t { SPADES = 0, HEARTS, DIAMONDS, CLUBS }; 

	struct Card_t {

		const uint8_t suit;
		const char rank[3];
		const char * const draw;
	};

	struct Suit_t {

		const char * name;
		const char * symbol;
	};

	static const Suit_t SUITS[] = { 

		{ "Spades", "♠" }, 
		{ "Hearts", "♥" }, 
		{ "Diamonds", "♦" }, 
		{ "Clubs", "♣" }
	};

	static const Card_t DEFAULT_DECK[] {
		
		{ SPADES, "A", "🂡" }, { HEARTS, "A", "🂱" }, { DIAMONDS, "A", "🃁" }, { CLUBS, "A", "🃑" },
		{ SPADES, "2", "🂢" }, { HEARTS, "2", "🂲" }, { DIAMONDS, "2", "🃂" }, { CLUBS, "2", "🃒" },
		{ SPADES, "3", "🂣" }, { HEARTS, "3", "🂳" }, { DIAMONDS, "3", "🃃" }, { CLUBS, "3", "🃓" },
		{ SPADES, "4", "🂤" }, { HEARTS, "4", "🂴" }, { DIAMONDS, "4", "🃄" }, { CLUBS, "4", "🃔" },
		{ SPADES, "5", "🂥" }, { HEARTS, "5", "🂵" }, { DIAMONDS, "5", "🃅" }, { CLUBS, "5", "🃕" },
		{ SPADES, "6", "🂦" }, { HEARTS, "6", "🂶" }, { DIAMONDS, "6", "🃆" }, { CLUBS, "6", "🃖" },
		{ SPADES, "7", "🂧" }, { HEARTS, "7", "🂷" }, { DIAMONDS, "7", "🃇" }, { CLUBS, "7", "🃗" },
		{ SPADES, "8", "🂨" }, { HEARTS, "8", "🂸" }, { DIAMONDS, "8", "🃈" }, { CLUBS, "8", "🃘" },
		{ SPADES, "9", "🂩" }, { HEARTS, "9", "🂹" }, { DIAMONDS, "9", "🃉" }, { CLUBS, "9", "🃙" },
		{ SPADES, "10", "🂪" }, { HEARTS, "10", "🂺" }, { DIAMONDS, "10", "🃊" }, { CLUBS, "10", "🃚" },
		{ SPADES, "J", "🂫" }, { HEARTS, "J", "🂻" }, { DIAMONDS, "J", "🃋" }, { CLUBS, "J", "🃛" },
		{ SPADES, "Q", "🂭" }, { HEARTS, "Q", "🂽" }, { DIAMONDS, "Q", "🃍" }, { CLUBS, "Q", "🃝" },
		{ SPADES, "K", "🂮" }, { HEARTS, "K", "🂾" }, { DIAMONDS, "K", "🃎" }, { CLUBS, "K", "🃞" }
	};

	static constexpr int DEFAULT_DECK_SIZE = (int) sizeof(DEFAULT_DECK) / sizeof(Card_t);
}

#endif