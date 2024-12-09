#pragma once
#ifndef NODE_H
#define NODE_H

#include <string>
#include "Game.h"
using namespace std;

class Node
{
public:
	Node();
	Node(const Game& gameInput);
	void setGame(const Game& gameInput);
	Game getGame() const;
	Node* getNext() const;
	Node* getPrev() const;
	void setNext(Node* nxt);
	void setPrev(Node* prv);
	bool operator==(const Node& other) const;
	bool operator!=(const Node& other) const;
private:
	Game game;
	Node* next;
	Node* prev;
};



#endif