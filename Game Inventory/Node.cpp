#include "Node.h"

Node::Node() : game(nullptr), next(nullptr), prev(nullptr) {}

Node::Node(Game* gameInput) : game(gameInput), next(nullptr), prev(nullptr) {}

Node::~Node() {
}

void Node::setGame(Game* gameInput) {
	game = gameInput;
}

Game* Node::getGame() const {
	return game;
}

Node* Node::getNext() const {
	return next;
}

Node* Node::getPrev() const {
	return prev;
}

void Node::setNext(Node* nxt) {
	next = nxt;
}

void Node::setPrev(Node* prv) {
	prev = prv;
}

bool Node::operator==(const Node& other) const {
	return game == other.game;
}

bool Node::operator!=(const Node& other) const {
	return !(*this == other);
}