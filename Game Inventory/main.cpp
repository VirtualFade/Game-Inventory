/*
Author(s): Joshua Oakes, Rama Harish Varma Vegesna

Goal: create an inventory of games that stores all the necessary information a game would contain.

TO DO: Add linked lists for each type of game
	When adding game, give option for physical or digital, and what platform they're on
*/

#include "GameInventory.h"
#include "Platform.h"
#include "Game.h"
#include "DigitalGame.h"
#include "PhysicalGame.h"

#include <string>
#include <iostream>
using namespace std;

enum Actions {QUIT, COUNT, PRINT_GAMES, ADD_GAME, SEARCH, DELETE_GAME, PLATFORM_LIST};
const int min_menu_option = COUNT;
const int max_menu_option = PLATFORM_LIST;

GameInventory digitalInventory;
GameInventory physicalInventory;
GameInventory fullInventory;

void displayMenu();
void menuChoice(int choice);
void runChoice();

int main() {
	runChoice();
	return 0;
}

void displayMenu() {
	cout << " Game Inventory: " << endl;
	cout << " (" << COUNT << ")" << "Count the number of games in inventory" << endl;
	cout << " (" << PRINT_GAMES << ") Print all game titles available" << endl;
	cout << " (" << ADD_GAME << ") Add game to inventory" << endl;
	cout << " (" << SEARCH << ") Find game title in inventory" << endl;
	cout << " (" << DELETE_GAME << ") Remove game from inventory" << endl;
	cout << " (" << PLATFORM_LIST << ") Displays all platforms available" << endl;
	cout << "Enter a number from " << min_menu_option << " to " << max_menu_option << ", or " << QUIT << " to exit" << endl;
}

void menuChoice(int choice) {
	switch (choice) {
	case COUNT:
		cout << "COUNT not yet implemented" << endl;
		break;
	case PRINT_GAMES:
		cout << "PRINT_GAMES not yet implemented" << endl;
		break;
	case ADD_GAME:
		cout << "ADD_GAME not yet implemented" << endl;
		break;
	case SEARCH:
		cout << "SEARCH not yet implemented" << endl;
		break;
	case DELETE_GAME:
		cout << "DELETE_GAME not yet implemented" << endl;
		break;
	case PLATFORM_LIST:
		cout << "PLATFORM_LIST not yet implemented" << endl;
		break;
	case QUIT:
		break;
	default:
		cout << "ERROR! Your choice was not part of the options available, please select another option." << endl;
	}
}

void runChoice() {
	int userChoice = -1;

	while (userChoice != QUIT) {
		displayMenu();
		cin >> userChoice;

		menuChoice(userChoice);
	}
	cout << "Goodbye!" << endl;
}
