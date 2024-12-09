#pragma once
#ifndef PHYSICALGAME_H
#define PHYSICALGAME_H

#include "Game.h"
#include <iostream>
using namespace std;

class PhysicalGame : public Game {
private:
    bool isCollectorEdition;  // Whether it's a collector's edition
    float discSize;           // Size of the disc in GB

public:
    PhysicalGame();
    PhysicalGame(const string& title, const string& genre, int year, const Platform& platform, bool isCollectorEdition, float discSize);

    // Setters
    void setIsCollectorEdition(bool isCollectorEdition);
    void setDiscSize(float discSize);

    // Getters
    bool getIsCollectorEdition() const;
    float getDiscSize() const;

    // Override displayInfo to include new attributes
    void displayInfo() const override;
};

#endif


