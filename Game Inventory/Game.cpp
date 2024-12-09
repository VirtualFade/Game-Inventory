#include "Game.h"


Game::Game() : title("Unknown"), genre("Unknown"), year(0), platform() {}

Game::Game(const string& title, const string& genre, int year, const Platform& platform) : title(title), genre(genre), year(year), platform(platform) {}

void Game::setTitle(const string& title) {
	this->title = title;
}

void Game::setGenre(const string& genre) {
	this->genre = genre;
}

void Game::setYear(int year) {
	this->year = year;
}

void Game::setPlatform(const Platform& platform) {
	this->platform = platform;
}

string Game::getTitle() const {
	return title;
}

string Game::getGenre() const {
	return genre;
}

int Game::getYear() const {
	return year;
}

Platform Game::getPlatform() const {
	return platform;
}

void Game::printInfo() const {
	cout << "Title: " << title << endl;
	cout << "Genre: " << genre << endl;
	cout << "Year: " << year << endl;
	cout << "Platform: " << platform.getName() << " (" << platform.getManufacturer() << ", Released: " << platform.getReleaseYear() << ")" << endl;
}

bool Game::operator==(const Game& other) const {
	return title == other.title && genre == other.genre && year == other.year &&
		platform.getName() == other.platform.getName() &&
		platform.getManufacturer() == other.platform.getManufacturer() &&
		platform.getReleaseYear() == other.platform.getReleaseYear();
}

bool Game::operator!=(const Game& other) const {
	return !(*this == other);
}