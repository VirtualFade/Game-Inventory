#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include "Platform.h"
using namespace std;

class Game
{
protected: //switched to protected for easy access from subclasses
	string title;
	string genre;
	int year;
	Platform platform;
public:
	Game();
	Game(const string& title, const string& genre, int year, const Platform& platform);
	virtual ~Game(); //destructor for game and its subclasses

	void setTitle(const string& title);
	void setGenre(const string& genre);
	void setYear(int year);
	void setPlatform(const Platform& platform);
	string getTitle() const;
	string getGenre() const;
	int getYear() const;
	Platform getPlatform() const;
	virtual void printInfo() const; //printinfo for game and subclasses
	bool operator==(const Game& other) const;
	bool operator!=(const Game& other) const;
};

#endif
