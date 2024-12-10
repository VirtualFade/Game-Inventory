#include "GameInventory.h"

GameInventory::GameInventory() : head(nullptr), tail(nullptr), size(0) {}

GameInventory::~GameInventory() {
	Node* current = this->head;
	while (current != nullptr) {
		Node* toDelete = current;
		current = current->getNext();
		delete toDelete->getGame();
		delete toDelete;
	}
}

void GameInventory::addGame(Game* game) {
	Node* newNode = new Node(game);

	if (this->isEmpty()) {
		this->head = this->tail = newNode;
	}
	else {
		Node* current = this->head;
		while (current != nullptr && current->getGame()->getTitle() < game->getTitle()) {
			current = current->getNext();
		}
		if (current == this->head) {
			newNode->setNext(this->head);
			this->head->setPrev(newNode);
			this->head = newNode;
		}
		else if (current == nullptr) {
			this->tail->setNext(newNode);
			newNode->setPrev(this->tail);
			this->tail = newNode;
		}
		else {
			Node* prevNode = current->getPrev();
			prevNode->setNext(newNode);
			newNode->setPrev(prevNode);
			newNode->setNext(current);
			current->setPrev(newNode);
		}
	}
	size++;
}

bool GameInventory::removeGame(const string& title) {
	Node* current = this->head;

	while (current != nullptr) {
		if (current->getGame()->getTitle() == title) {
			if (current->getPrev() != nullptr) {
				current->getPrev()->setNext(current->getNext());
			}
			else {
				this->head = current->getNext();
			}

			if (current->getNext() != nullptr) {
				current->getNext()->setPrev(current->getPrev());
			}
			else {
				this->tail = current->getPrev();
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
	Node* current = this->head;

	while (current != nullptr) {
		if (current->getGame()->getTitle() == title) {
			return current;
		}
		current = current->getNext();
	}
	return nullptr;
}

void GameInventory::displayAll() const {
	Node* current = this->head;

	while (current != nullptr) {
		current->getGame()->printInfo();
		cout << "------------------------" << endl;
		current = current->getNext();
	}
}

bool GameInventory::isEmpty() const {
	return this->head == nullptr;
}

int GameInventory::getSize() const {
	return size;
}
