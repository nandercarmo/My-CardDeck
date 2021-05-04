/*
 *  exception.h
 *  Created on: Apr 2021
 *  Author: Nander Carmo
 *  Version: 1.0
 *  License: MIT
 * 	Based on the Bill Weinman code taken from https://bw.org/cpp/
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

	const Exception EXCEPTION_DECK_NOT_CREATED("\nDeck not created yet!\n");
	const Exception EXECPTION_INVALID_DECK_NUMBER("\nNumber of deck must be a integer between 1 and 10!\n");
	const Exception EXECPTION_INVALID_DEAL_CARDS_NUMBER("\nNumber of cards to deal must be a integer between 1 and the number of cards remaining in the deck!\n");
	const Exception EXECPTION_INVALID_CARD_TO_DISCARD("\nIndex of the card to discard must be a integer between 0 and the number of the cards in the hand!\n");
}

#endif