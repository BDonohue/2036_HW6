#ifndef Ship_H
#define Ship_H

#include "globals.h"
class Ship
{
    public:
    explicit Ship(int x, int y, int z);
    //Setters and Getters
    void setXPosition(int x);
    void setYPosition(int y);
    void setXWidth(int x);
    void setDirection(int dir);
    void setDestroyed(int des);
    int getXPosition();
    int getYPosition();
    int getXWidth();
    int getDirection();
    int getDestroyed();
    //Functions
    virtual void move(int dist);    //move "dist" along the x axis
    virtual void draw();            //draw the ship
    virtual void update();          //update the ship, then draw
    void destroy();                 //destroy the ship
    
    private:
    int xPosition;  //y Position
    int yPosition;  //x Position
    int xWidth;     //used to detect collisions at edge of screen
    int direction;  //direction 0: move right; direction 1: move left;
    int destroyed;  //destroyed 0: ship alive; destroyed 1: ship dead;
};

#endif