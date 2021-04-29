/*
 *  exception.h
 *  Created on: Apr 2021
 *  Author: Nander Carmo
 *  Version: 1.0
 *  License: MIT
 */

#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <exception>

namespace My {

	class Exception : public std::exception {

		const char * _message;
		Exception();

	public:

		Exception(const char * message) noexcept(true) : _message(message) {};
		const char * what () const noexcept(true) { return _message; };
	};

	const Exception EXCEPTION_DECK_NOT_CREATED("\nERRO: Deck not created yet!\n");
	const Exception EXECPTION_INVALID_DECK_NUMBER("\nERRO: Number of deck must be between 1 and 10!\n");
	const Exception EXECPTION_INVALID_DEAL_CARDS_NUMBER("\nERRO: Number of cards to deal must be between 1 and the number of cards remaining in the deck!\n");
	const Exception EXECPTION_INVALID_CARD_TO_DISCARD("\nERRO: Index of the card to discard must be between 0 and the number of the cards in the hand!\n");
}

#endif