#include "DigitalGame.h"
#include <iostream>

// Default constructor
DigitalGame::DigitalGame() : Game(), downloadSize(0.0) {}

// Parameterized constructor
DigitalGame::DigitalGame(const std::string& title, const std::string& genre, int year, const Platform& platform,
                         double downloadSize)
    : Game(title, genre, year, platform), downloadSize(downloadSize) {}

DigitalGame:~DigitalGame() {}

// Setter for downloadSize
void DigitalGame::setDownloadSize(double size) {
    this->downloadSize = size;
}

// Getter for downloadSize
double DigitalGame::getDownloadSize() const {
    return downloadSize;
}

// Overridden printInfo to display game details along with download size
void DigitalGame::printInfo() const {
    Game::printInfo(); // Call the base class printInfo
    std::cout << "Download Size: " << downloadSize << " GB" << std::endl;
}
