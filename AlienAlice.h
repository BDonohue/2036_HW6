#ifndef AlienAlice_H
#define AlienAlice_H

#include "Ship.h"
#include "globals.h"

class AlienAlice : public Ship
{
    public:
    explicit AlienAlice(int x, int y); 
    void AlienAlice::draw();
    void AlienAlice::update();
}; 

#endif