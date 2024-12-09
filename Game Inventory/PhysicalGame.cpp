#include "PhysicalGame.h"

PhysicalGame::PhysicalGame() 
    : Game(), isCollectorEdition(false), discSize(0.0f) {}

PhysicalGame::PhysicalGame(const string& title, const string& genre, int year, const Platform& platform, bool isCollectorEdition, float discSize)
    : Game(title, genre, year, platform), isCollectorEdition(isCollectorEdition), discSize(discSize) {}

void PhysicalGame::setIsCollectorEdition(bool isCollectorEdition) {
    this->isCollectorEdition = isCollectorEdition;
}

void PhysicalGame::setDiscSize(float discSize) {
    this->discSize = discSize;
}

bool PhysicalGame::getIsCollectorEdition() const {
    return isCollectorEdition;
}

float PhysicalGame::getDiscSize() const {
    return discSize;
}

void PhysicalGame::displayInfo() const {
    // Call the base class method to print common info
    Game::printInfo();

    // Add specific information for PhysicalGame
    cout << "Collector's Edition: " << (isCollectorEdition ? "Yes" : "No") << endl;
    cout << "Disc Size: " << discSize << " GB" << endl;
}
