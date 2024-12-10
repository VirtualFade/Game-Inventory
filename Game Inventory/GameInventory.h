#pragma once
#ifndef GAMEINVENTORY_H
#define GAMEINVENTORY_H

#include "Node.h"
#include <iostream>
using namespace std;

class GameInventory
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	GameInventory();
	~GameInventory();

	void addGame(Game* game);
	bool removeGame(const string& title);
	Node* searchGame(const string& title) const;
	void displayAll() const;
	int getSize() const;

	bool isEmpty() const;
};

#endif