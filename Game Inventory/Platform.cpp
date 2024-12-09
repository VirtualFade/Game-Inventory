#include "Platform.h"

// Predefined platforms
Platform ps5("PS5", "Sony", 2020);
Platform xbox("Xbox Series X", "Microsoft", 2020);
Platform switchConsole("Nintendo Switch", "Nintendo", 2017);

// Array or list of predefined platforms for selection
Platform platforms[] = {ps5, xbox, switchConsole};
const int NUM_PLATFORMS = 3; // Number of platforms available

Platform::Platform() : name("Unknown"), manufacturer("Unknown"), releaseYear(0) {}

Platform::Platform(const string& name, const string& manufacturer, int releaseYear) : name(name), manufacturer(manufacturer), releaseYear(releaseYear) {}

void Platform::setName(const string& name) {
	this->name = name;
}

void Platform::setManufacturer(const string& manufacturer) {
	this->manufacturer = manufacturer;
}

void Platform::setReleaseYear(int releaseYear) {
	this->releaseYear = releaseYear;
}

string Platform::getName() const {
	return name;
}

string Platform::getManufacturer() const {
	return manufacturer;
}

int Platform::getReleaseYear() const {
	return releaseYear;
}

void Platform::printInfo() const {
	cout << "Platform Name: " << name << endl;
	cout << "Manufacturer: " << manufacturer << endl;
	cout << "Release Year: " << releaseYear << endl;
}
