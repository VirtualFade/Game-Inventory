#pragma once
#ifndef PLATFORM_H
#define PLATFORM_H

#include <string>
#include <iostream>
using namespace std;
class Platform
{
private:
	string name;
	string manufacturer;
	int releaseYear;
public:
	Platform();
	Platform(const string& name, const string& manunfacturer, int releaseYear);
	void setName(const string& name);
	void setManufacturer(const string& manufacturer);
	void setReleaseYear(int releaseYear);
	string getName() const;
	string getManufacturer() const;
	int getReleaseYear() const;
	void printInfo() const;
};

#endif