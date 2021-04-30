#include <cerrno>

#include "deck.h"

enum UserChoice_e : uint8_t {

	PRINT_DECK = 1,
	PRINT_HAND,
	SHUFFLE,
	DEAL_CARDS,
	DISCARD,
	CHANGE_PRINT_MODE,
	PRINT_MATCH_SCOPE,
	QUIT
};

int getUserInput();
void getUsername();
void createDeck(My::Deck &);
void definePrintMode(My::Deck &);
void mainLoop(My::Deck &);

char username[100];

int main() {

	My::Deck deck;

	getUsername();	
	createDeck(deck);
	definePrintMode(deck);
	mainLoop(deck);	

    return errno; 
}

void getUsername() {

	printf("\n\n========================================== WELCOME TO MY-DECK!!! ==========================================\n\n");
	printf("How do you like to be called?\n\n");
	printf(">> ");
	fflush(stdout);

	scanf("%[^\n]s", username);
	printf("\n");
}

int getUserInput() {

	int userChoice = 0;

	printf("%s >> ", username);
	fflush(stdout);

	scanf("%i", &userChoice);
	printf("\n");

	return userChoice;
}

void createDeck(My::Deck & deck) {

	int skip = 0;

	while (!skip) {
		
		try {

			printf("\n===========================================================================================================\n\n");
			printf("Hi, %s!!!\n\n", username);
			printf("How many decks do you want to create? (Máx. 10)\n\n");

			deck.newDeck(getUserInput());

			skip = 1;

		} catch(My::Exception & e) {

			printf("%s\n", e.what());
			skip = 0;
		}
	}
}

void definePrintMode(My::Deck & deck) {

	int userChoice = 0;
	int skip = 0;

	while(!skip) {

		skip = 1;

		printf("\n===========================================================================================================\n\n");
		printf("Choose how you want to visualize the cards:\n\n");
		printf("1 - Use the cards drawings\n");
		printf("2 - Use the rank and suit form\n");
		printf("3 - Use the text\n\n");

		userChoice = getUserInput();

		switch (userChoice) {

			case My::DRAW: 
				
				deck.setPrintMode(My::DRAW); 
				break;

			case My::RANK_SUIT: 
				
				deck.setPrintMode(My::RANK_SUIT); 
				break;

			case My::TEXT: 
				
				deck.setPrintMode(My::TEXT); 
				break;

			default: 
									
				printf("Please choose one of the options above!\n");
				skip = 0; 
				break;
		}
	}
}

void mainLoop(My::Deck & deck) {
	
	int userChoice = 0;
	int skip = 0;

	while(!skip) {

		try {

			printf("\n===========================================================================================================\n\n");
			printf("What you wanna do now?\n\n");
			printf("1 - Print the deck\n");
			printf("2 - Print hand\n");
			printf("3 - Shuffle the deck\n");
			printf("4 - Deal cards\n");
			printf("5 - Discard\n");
			printf("6 - Change print mode\n");
			printf("7 - Print match scope\n");
			printf("8 - Quit\n\n");

			userChoice = getUserInput();

			switch (userChoice) {

				case PRINT_DECK: 
					
					deck.printDeck();
					break;

				case PRINT_HAND: 
					
					deck.printHand();
					break;

				case SHUFFLE: 
					
					deck.shuffle();
					break;

				case DEAL_CARDS: 
										
					printf("How many cards do you want to deal?\n\n");
					deck.dealCards(getUserInput());
					break;

				case DISCARD: 

					deck.printHand();
					printf("\nType the index of the card you want to discard:\n\n");
					deck.discardCard(getUserInput() - 1);
					break;

				case CHANGE_PRINT_MODE:

					definePrintMode(deck);
					break;

				case PRINT_MATCH_SCOPE:

					deck.printRaw();
					break;

				case QUIT:

					printf("Bye!\n\n");
					skip = 1; 
					break;

				default: printf("Please choose one of the options above!\n"); break;
			}

		} catch(My::Exception & e) {

			printf("%s\n", e.what());
		}
	}
}
