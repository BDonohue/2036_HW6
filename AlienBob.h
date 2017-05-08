#ifndef AlienBob_H
#define AlienBob_H

#include "Ship.h"
#include "globals.h"

class AlienBob : public Ship
{
    public:
    explicit AlienBob(int x, int y); 
    void AlienBob::draw();
    void AlienBob::update();
    //Getter/Setter for upDown
    void AlienBob::setUpDown(int input);
    int AlienBob::getUpDown();
    
    private:
    int upDown;     //0 = Wings down; 1 = Wings up; used for sprite
}; 

#endif