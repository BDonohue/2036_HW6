#include "Ship.h"

Ship::Ship(int x, int y, int z){
    setXPosition(x);
    setYPosition(y);
    setXWidth(z);
    setDirection(0);        //ships start out going right
    setDestroyed(0);        
}

void Ship::setXPosition(int x){
    xPosition = x;
}

void Ship::setYPosition(int y){
    yPosition = y;
}

void Ship::setXWidth(int x){
    xWidth = x;
} 

void Ship::setDirection(int dir){
    direction = dir;
}

void Ship::setDestroyed(int des){
    destroyed = des;    
}

int Ship::getXPosition(){
    return xPosition;   
}

int Ship::getYPosition(){
    return yPosition;
}

int Ship::getXWidth(){
    return xWidth;   
}

int Ship::getDirection(){
    return direction;   
}

int Ship::getDestroyed(){
    return destroyed;   
}

void Ship::move(int dist){
    //Check which way the ship is going
    if(direction == 0){
        xPosition += dist;
    } else {
        xPosition -= dist;
    }
    //Check if ship reaches the edge; if so, change directions
    if(getXPosition() + getXWidth() > 117){
        setXPosition(117 - getXWidth()); 
        setDirection(1);
    }
    if(getXPosition() - getXWidth() < 0){
        setXPosition(getXWidth());
        setDirection(0);
    }
}

void Ship::destroy(){
    setDestroyed(1);
    #define _ 0x000000 
    int Blank_sprite[ALIEN_WIDTH * ALIEN_HEIGHT] = {
        _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    };
    #undef _
    uLCD.BLIT(getXPosition(), getYPosition(), ALIEN_WIDTH, ALIEN_HEIGHT, Blank_sprite);      
}

void Ship::draw(){
}

void Ship::update(){
}