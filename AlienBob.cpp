#include "AlienBob.h"

AlienBob::AlienBob(int x, int y) : Ship(x, y, ALIEN_WIDTH){
    setUpDown(0);
}   

void AlienBob::draw(){
    //Bob flaps wings up and down; Also notice how he changes colors
    if(getUpDown() == 0){
        #define _ 0x000000
        #define X 0x0000FF
        int alienBobDown_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
            _,_,_,_,X,_,_,_,_,_,X,_,_,_,_,
            _,_,_,_,_,X,_,_,_,X,_,_,_,_,_,
            _,_,_,_,X,X,X,X,X,X,X,_,_,_,_,
            _,_,_,X,X,_,X,X,X,_,X,X,_,_,_,
            _,_,X,X,X,X,X,X,X,X,X,X,X,_,_,
            _,_,X,_,X,X,X,X,X,X,X,_,X,_,_,
            _,_,X,_,X,_,_,_,_,_,X,_,X,_,_,
            _,_,_,_,_,X,X,_,X,X,_,_,_,_,_,
        };
        #undef _
        #undef X
        uLCD.BLIT(getXPosition(), getYPosition(), ALIEN_WIDTH, ALIEN_HEIGHT, alienBobDown_sprite);
        setUpDown(1);
    } else {
        #define _ 0x000000
        #define X 0x00FFFF
        int alienBobUp_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
            _,_,_,_,X,_,_,_,_,_,X,_,_,_,_,
            _,_,X,_,_,X,_,_,_,X,_,_,X,_,_,
            _,_,X,_,X,X,X,X,X,X,X,_,X,_,_,
            _,_,X,X,X,_,X,X,X,_,X,X,X,_,_,
            _,_,X,X,X,X,X,X,X,X,X,X,X,_,_,
            _,_,_,_,X,X,X,X,X,X,X,_,_,_,_,
            _,_,_,_,X,_,_,_,_,_,X,_,_,_,_,
            _,_,_,X,_,_,_,_,_,_,_,X,_,_,_,
        };
        #undef _
        #undef X
        uLCD.BLIT(getXPosition(), getYPosition(), ALIEN_WIDTH, ALIEN_HEIGHT, alienBobUp_sprite);
        setUpDown(0);
    }
}

void AlienBob::update(){
    move(1);
    draw();
}

void AlienBob::setUpDown(int input){
    upDown = input;   
}

int AlienBob::getUpDown(){
    return upDown;
}


