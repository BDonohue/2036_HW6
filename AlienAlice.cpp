#include "AlienAlice.h"

AlienAlice::AlienAlice(int x, int y) : Ship(x, y, ALIEN_WIDTH){
}   

void AlienAlice::draw(){
    #define _ 0x000000 
    #define X 0xFF00FF 
    int alienAlice_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
        _,_,_,_,_,_,X,X,X,_,_,_,_,_,_,
        _,_,_,X,X,X,X,X,X,X,X,X,_,_,_,
        _,_,X,X,X,X,X,X,X,X,X,X,X,_,_,
        _,_,X,X,X,_,_,X,_,_,X,X,X,_,_,
        _,_,X,X,X,X,X,X,X,X,X,X,X,_,_,
        _,_,_,_,_,X,X,_,X,X,_,_,_,_,_,
        _,_,_,_,X,X,_,_,_,X,X,_,_,_,_,
        _,_,X,X,_,_,_,X,_,_,_,X,X,_,_,
    };

    #undef _
    #undef X
    uLCD.BLIT(getXPosition(), getYPosition(), ALIEN_WIDTH, ALIEN_HEIGHT, alienAlice_sprite);
}

void AlienAlice::update(){
    move(2);    //alice moves 2 spaces at a time
    draw();
}

