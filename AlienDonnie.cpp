#include "AlienDonnie.h"

AlienDonnie::AlienDonnie(int x, int y) : Ship(x, y, ALIEN_WIDTH){
}   

void AlienDonnie::draw(){
    #define _ 0x000000 //BLACK
    #define X 0x66FF33 //WHITE
    int alienDonnie_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
        _,_,_,_,_,X,X,X,X,X,_,_,_,_,_,
        _,_,_,_,X,X,X,X,X,X,X,_,_,_,_,
        _,_,_,X,X,_,X,X,X,_,X,X,_,_,_,
        _,_,X,X,X,X,X,X,X,X,X,X,X,_,_,
        _,_,X,X,X,X,X,X,X,X,X,X,X,_,_,
        _,_,_,_,X,_,_,_,_,_,X,_,_,_,_,
        _,_,_,X,_,X,X,X,X,X,_,X,_,_,_,
        _,_,X,_,X,_,_,_,_,_,X,_,X,_,_,

    };

    #undef _
    #undef X
    uLCD.BLIT(getXPosition(), getYPosition(), ALIEN_WIDTH, ALIEN_HEIGHT, alienDonnie_sprite);   
}

void AlienDonnie::update(){
    //Donnie moves 1 space, then 2 space
    if((getXPosition() % 2) == 1){
        move(1);
    } else {
        move(2);
    }
    draw();
}

