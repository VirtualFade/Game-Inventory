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

GameInventory* digitalInventory = new GameInventory();
GameInventory* physicalInventory = new GameInventory();
GameInventory* fullInventory = new GameInventory();

void displayMenu();
void menuChoice(int choice);
void runChoice();
void countMenu();
void inventoryChoice();
void printMenu();
void addMenu();
void addPhysical();
void addDigital();
void deleteMenu();
void initialGames();

int main() {
	initialGames();
	runChoice();
	delete fullInventory;
	return 0;
}

void initialGames() {
	Game* PhysGame = new PhysicalGame("The last of us Part II", "Action-Adventure", 2020, ps5, false, 50);
	physicalInventory->addGame(PhysGame);
	fullInventory->addGame(PhysGame);
	Game* PhysGame2 = new PhysicalGame("Super Mario Party Jamboree", "Party", 2024, switchConsole, false, 5.3);
	physicalInventory->addGame(PhysGame2);
	fullInventory->addGame(PhysGame2);
	Game* PhysGame3 = new PhysicalGame("Halo Infinite", "First-Person Shooter", 2021, xbox, true, 34);
	physicalInventory->addGame(PhysGame3);
	fullInventory->addGame(PhysGame3);

	Game* DigGame = new DigitalGame("Call of Duty: Black Ops 6", "First-Person Shooter", 2024, xbox, 85.56);
	digitalInventory->addGame(DigGame);
	fullInventory->addGame(DigGame);
	Game* DigGame2 = new DigitalGame("The Legend of Zelda: Breath of the Wild", "Action RPG", 2017, switchConsole, 13.4);
	digitalInventory->addGame(DigGame2);
	fullInventory->addGame(DigGame2);
	Game* DigGame3 = new DigitalGame("Sonic Frontiers", "Platformer", 2022, ps5, 10.4);
	digitalInventory->addGame(DigGame3);
	fullInventory->addGame(DigGame3);

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
		addMenu();
		break;
	case SEARCH:
		cout << "SEARCH not yet implemented" << endl;
		break;
	case DELETE_GAME:
		deleteMenu();
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
			cout << "There are " << physicalInventory->getSize() << " physical games available." <<endl;
			break;
		case 2:
			cout << "There are " << digitalInventory->getSize() << " digital games available." << endl;
			break;
		case 3:
			cout << "There are " << fullInventory->getSize() << " total games available." << endl;
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
			physicalInventory->displayAll();
			break;
		case 2:
			cout << "Digital Games available" << endl;
			cout << "------------------------" << endl;
			digitalInventory->displayAll();
			break;
		case 3:
			cout << "Total Games available" << endl;
			cout << "------------------------" << endl;
			fullInventory->displayAll();
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

void addMenu() {
	int addChoice = -1;
	do {

		cout << "Select Inventory to add game to" << endl;
		cout << "-----------------------------------" << endl;
		cout << "(1) Physical Games Inventory" << endl;
		cout << "(2) Digital Games Inventory" << endl;
		cout << "(0) Return to Menu" << endl;
		cin >> addChoice;
		switch (addChoice) {
		case 1:
			addPhysical();
			break;
		case 2:
			addDigital();
			break;
		case 0:
			cout << "Returning to menu." << endl;
			break;
		default:
			cout << "Option not available, try again." << endl;
		}
	} while (!(addChoice >= 0 && addChoice <= 3));
}

void addPhysical() {
	string title;
	string genre;
	int year;
	string platform;
	Game* physical = new PhysicalGame();
	PhysicalGame* physicalGame = dynamic_cast<PhysicalGame*>(physical);
	bool isCollectors;
	float discSize;

	cout << "What is the title of the game?" << endl;
	cin.ignore();
	getline(cin, title);
	physical->setTitle(title);

	cout << "What genre is it?" << endl;
	getline(cin, genre);
	physical->setGenre(genre);

	cout << "What year was it released?" << endl;
	cin >> year;
	physical->setYear(year);

	cout << "Choose a platform for the game (PS5, Xbox, Switch)" << endl;
	cin >> platform;

	if (platform == "PS5") {
		physical->setPlatform(ps5);
	}
	else if (platform == "Xbox") {
		physical->setPlatform(xbox);
	}
	else if (platform == "Switch") {
		physical->setPlatform(switchConsole);
	}
	else {
		cout << "Invalid platform choice!" << endl;
	}

	cout << "Is this a collector's edition?(0 = false, 1 = true)" << endl;
	cin >> isCollectors;
	physicalGame->setIsCollectorEdition(isCollectors);

	cout << "What is the disc size?" << endl;
	cin >> discSize;
	physicalGame->setDiscSize(discSize);

	physicalInventory->addGame(physical);
	fullInventory->addGame(physical);

}

void addDigital() {
	string title;
	string genre;
	int year;
	string platform;
	Game* digital = new DigitalGame();
	DigitalGame* digitalGame = dynamic_cast<DigitalGame*>(digital);
	float downloadSize;

	cout << "What is the title of the game?" << endl;
	cin.ignore();
	getline(cin, title);
	digital->setTitle(title);

	cout << "What genre is it?" << endl;
	getline(cin, genre);
	digital->setGenre(genre);

	cout << "What year was it released?" << endl;
	cin >> year;
	digital->setYear(year);

	cout << "Choose a platform for the game (PS5, Xbox, Switch)" << endl;
	cin >> platform;

	if (platform == "PS5") {
		digital->setPlatform(ps5);
	}
	else if (platform == "Xbox") {
		digital->setPlatform(xbox);
	}
	else if (platform == "Switch") {
		digital->setPlatform(switchConsole);
	}
	else {
		cout << "Invalid platform choice!" << endl;
	}

	cout << "What is the download size?" << endl;
	cin >> downloadSize;
	digitalGame->setDownloadSize(downloadSize);

	digitalInventory->addGame(digital);
	fullInventory->addGame(digital);

}

void deleteMenu() {
	string game;
	int deleteChoice = -1;
	cout << "Select Inventory to remove game from" << endl;
	cout << "-----------------------------------" << endl;
	cout << "(1) Physical Games Inventory" << endl;
	cout << "(2) Digital Games Inventory" << endl;
	cout << "(0) Return to Menu" << endl;
	cin >> deleteChoice;
	if (deleteChoice == 1) {
		cout << "Physical Games available" << endl;
		cout << "------------------------" << endl;
		physicalInventory->displayAll();
		cout << "What game would you like to remove from the inventory?" << endl;
		cin.ignore();
		getline(cin, game);
		physicalInventory->removeGame(game);
		fullInventory->removeGame(game);
		cout << game << " has been removed from the inventory." << endl;
	}
	else if (deleteChoice == 2) {
		cout << "Digital Games available" << endl;
		cout << "------------------------" << endl;
		digitalInventory->displayAll();
		cout << "What game would you like to remove from the inventory?" << endl;
		cin.ignore();
		getline(cin, game);
		digitalInventory->removeGame(game);
		fullInventory->removeGame(game);
		cout << game << " has been removed from the inventory." << endl;
	}
}
