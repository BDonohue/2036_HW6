#include "AlienCharlie.h"

AlienCharlie::AlienCharlie(int x, int y) : Ship(x, y, ALIEN_WIDTH){
}   

void AlienCharlie::draw(){
    #define _ 0x000000 //BLACK
    #define X 0xFF0000 //WHITE
    int alienCharlie_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
        _,_,_,_,_,_,_,X,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,X,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,X,_,_,_,_,_,_,_,
        _,_,_,_,_,_,X,X,X,_,_,_,_,_,_,
        _,_,_,_,X,X,X,X,X,X,X,_,_,_,_,
        _,_,X,X,X,X,X,X,X,X,X,X,X,_,_,
        _,_,X,X,X,X,X,X,X,X,X,X,X,_,_,
        _,_,_,X,X,X,X,X,X,X,X,X,_,_,_,
    };

    #undef _
    #undef X
    uLCD.BLIT(getXPosition(), getYPosition(), ALIEN_WIDTH, ALIEN_HEIGHT, alienCharlie_sprite);   
}

void AlienCharlie::update(){
    move(2);    //Charlie moves 2 spaces at a time
    draw();
}

