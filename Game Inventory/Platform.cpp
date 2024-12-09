#include "Platform.h"

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