#ifndef AlienDonnie_H
#define AlienDonnie_H

#include "Ship.h"
#include "globals.h"

class AlienDonnie : public Ship
{
    public:
    explicit AlienDonnie(int x, int y); 
    void AlienDonnie::draw();
    void AlienDonnie::update();
}; 

#endif