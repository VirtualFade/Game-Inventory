/*
Author(s): Joshua Oakes, Rama Harish Varma Vegesna

Goal: create an inventory of games that stores all the necessary information a game would contain.

TO DO: Add linked lists for each type of game
	When adding game, give option for physical or digital, and what platform they're on
*/

#include "GameInventory.h"
#include "Platform.h"
#include "Game.h"

#include <string>
#include <iostream>
using namespace std;

enum Actions {QUIT, COUNT, PRINT_GAMES, ADD_GAME, LINEAR_SEARCH, DELETE_GAME, PLATFORM_LIST};
const int min_menu_option = COUNT;
const int max_menu_option = PLATFORM_LIST;

void displayMenu();

int main() {
}

void displayMenu() {
	cout << " Game Inventory: " << endl;
	cout << " (" << COUNT << ")" << "Count the number of games in inventory" << endl;
	cout << " (" << PRINT_GAMES << ") Print all game titles available" << endl;
	cout << " (" << ADD_GAME << ") Add game to inventory" << endl;
	cout << " (" << LINEAR_SEARCH << ") Find game title in inventory" << endl;
	cout << " (" << DELETE_GAME << ") Remove game from inventory" << endl;
	cout << " (" << PLATFORM_LIST << ") Displays all platforms available" << endl;
	cout << "Enter a number from " << min_menu_option << " to " << max_menu_option << ", or " << QUIT << " to exit" << endl;
}
