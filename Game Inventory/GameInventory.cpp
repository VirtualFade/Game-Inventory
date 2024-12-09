#include "GameInventory.h"

GameInventory::GameInventory() : head(nullptr), tail(nullptr) {}

GameInventory::~GameInventory() {
	Node* current = head;
	while (current != nullptr) {
		Node* toDelete = current;
		current = current->getNext();
		delete toDelete;
	}
}

void GameInventory::addGame(const Game& game) {
	Node* newNode = new Node(game);

	if (isEmpty()) {
		head = tail = newNode;
	}
	else {
		tail->setNext(newNode);
		newNode->setPrev(tail);
		tail = newNode;
	}
	size++;
}

bool GameInventory::removeGame(const string& title) {
	Node* current = head;

	while (current != nullptr) {
		if (current->getGame().getTitle() == title) {
			if (current->getPrev() != nullptr) {
				current->getPrev()->setNext(current->getNext());
			}
			else {
				tail = current->getPrev();
			}

			if (current->getNext() != nullptr) {
				current->getNext()->setPrev(current->getPrev());
			}
			else {
				tail = current->getPrev();
			}

			delete current;
			size--;
			return true;
		}
		current = current->getNext();
	}
	return false;
}

Node* GameInventory::searchGame(const string& title) const {
	Node* current = head;

	while (current != nullptr) {
		if (current->getGame().getTitle() == title) {
			return current;
		}
		current = current->getNext();
	}
	return nullptr;
}

void GameInventory::displayAll() const {
	Node* current = head;

	while (current != nullptr) {
		current->getGame().printInfo();
		cout << "------------------------" << endl;
		current = current->getNext();
	}
}

bool GameInventory::isEmpty() const {
	return head == nullptr;
}

int GameInventory::getSize() const {
	return size;
}