#ifndef Player_H
#define Player_H

#include "Ship.h"
#include "globals.h"

class Player : public Ship
{
    public:
    explicit Player(int x, int y); 
    void Player::draw();
    void Player::update();
    void Player::move(int dist);
    
    //Missile Commands
    void fire();
    void missileUpdate();
    void missileDestroy();
    
    //Missile Getters and Setters
    void setMissileX(int x);
    void setMissileY(int y);
    void setMissileState(int s);
    int getMissileX();
    int getMissileY();
    int getMissileState();
    
    private:
    int missileX;
    int missileY;
    int missileState;
}; 

#endif