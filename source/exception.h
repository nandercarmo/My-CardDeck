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
}

#endif