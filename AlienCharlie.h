#ifndef AlienCharlie_H
#define AlienCharlie_H

#include "Ship.h"
#include "globals.h"

class AlienCharlie : public Ship
{
    public:
    explicit AlienCharlie(int x, int y); 
    void AlienCharlie::draw();
    void AlienCharlie::update();
}; 

#endif