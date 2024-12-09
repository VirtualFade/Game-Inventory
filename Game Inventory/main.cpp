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
void countMenu();
void inventoryChoice();
void printMenu();

int main() {
	Game game1("The Witcher 3", "RPG", 2015);
	fullInventory.addGame(game1);
	runChoice();
	return 0;
}

void displayMenu() {
	cout << " Game Inventory: " << endl;
	cout << " (" << COUNT << ")" << "Count the number of games in inventory" << endl;
	cout << " (" << PRINT_GAMES << ") Print all game titles available in inventory" << endl;
	cout << " (" << ADD_GAME << ") Add game to inventory" << endl;
	cout << " (" << SEARCH << ") Find game title in inventory and display info" << endl;
	cout << " (" << DELETE_GAME << ") Remove game from inventory" << endl;
	cout << " (" << PLATFORM_LIST << ") Displays all platforms available" << endl;
	cout << "Enter a number from " << min_menu_option << " to " << max_menu_option << ", or " << QUIT << " to exit" << endl;
}

void menuChoice(int choice) {
	switch (choice) {
	case COUNT:
		countMenu();
		break;
	case PRINT_GAMES:
		printMenu();
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

void countMenu() {
	int countChoice = -1;
	do {
		inventoryChoice();

		cin >> countChoice;

		switch (countChoice) {
		case 1:
			cout << "There are " << physicalInventory.getSize() << " physical games available." <<endl;
			break;
		case 2:
			cout << "There are " << digitalInventory.getSize() << " digital games available." << endl;
			break;
		case 3:
			cout << "There are " << fullInventory.getSize() << " total games available." << endl;
			break;
		case 0:
			cout << "Returning to menu." << endl;
			break;
		default:
			cout << "Option not available, try again." << endl;
			break;
		}
	} while (!(countChoice >= 0 && countChoice <= 3));
	return;
}

void printMenu() {
	int printChoice = -1;
	do {
		inventoryChoice();

		cin >> printChoice;
		switch (printChoice) {
		case 1:
			cout << "Physical Games available" << endl;
			cout << "------------------------" << endl;
			physicalInventory.displayAll();
			break;
		case 2:
			cout << "Digital Games available" << endl;
			cout << "------------------------" << endl;
			digitalInventory.displayAll();
			break;
		case 3:
			cout << "Total Games available" << endl;
			cout << "------------------------" << endl;
			fullInventory.displayAll();
			break;
		case 0:
			cout << "Returning to menu." << endl;
			break;
		default:
			cout << "Option not available, try again." << endl;
		}
	} while (!(printChoice >= 0 && printChoice <= 3));
	return;
}

void inventoryChoice() {
	cout << "Select Inventory" << endl;
	cout << "-----------------------------------" << endl;
	cout << "(1) Physical Games Inventory" << endl;
	cout << "(2) Digital Games Inventory" << endl;
	cout << "(3) Total Games Inventory" << endl;
	cout << "(0) Return to Menu" << endl;
}