#pragma once
#ifndef DIGITALGAME_H
#define DIGITALGAME_H

#include "Game.h"
#include <string>

class DigitalGame : public Game {
private:
    float downloadSize; // Size of the game in GB

public:
    // Constructors
    DigitalGame();
    DigitalGame(const std::string& title, const std::string& genre, int year, const Platform& platform,
                float downloadSize);
    ~DigitalGame() override;

    // Setter for downloadSize
    void setDownloadSize(float size);

    // Getter for downloadSize
    float getDownloadSize() const;

    // Overridden printInfo method to include downloadSize
    void printInfo() const override;
};

#endif


