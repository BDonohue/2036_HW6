#include "Player.h"

Player::Player(int x, int y) : Ship(x, y, ALIEN_WIDTH){
    setMissileState(0);
}   

void Player::draw(){
    
    #define _ 0x000000 
    #define X 0xFFFFFF 
    #define R 0xFFFFFF
    #define Y 0xFFFFFF
    int Player_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
        _,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,
        _,_,_,_,_,_,Y,Y,Y,_,_,_,_,_,_,
        _,_,_,_,_,Y,Y,Y,Y,Y,_,_,_,_,_,
        _,_,_,_,Y,Y,Y,Y,Y,Y,Y,_,_,_,_,
        _,_,_,Y,Y,Y,Y,Y,Y,Y,Y,Y,_,_,_,
        _,_,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,_,_,
        _,_,_,_,R,R,_,_,_,R,R,_,_,_,_,
        _,_,_,_,R,R,_,_,_,R,R,_,_,_,_,
    };
    #undef _
    #undef X
    #undef R
    #undef Y
    Serial pc(USBTX,USBRX);
    pc.printf("\nPlayerB");
    uLCD.BLIT(getXPosition(), getYPosition(), 15, 8, Player_sprite);   
    pc.printf("\nPlayerA");
}

void Player::update(){
    draw();   
}

void Player::move(int dist){
    setXPosition(getXPosition() + dist);
    if(getXPosition() + getXWidth() > 117){
        setXPosition(117 - getXWidth()); 
    }
    if(getXPosition() - getXWidth() < 0){
        setXPosition(getXWidth());
    }
    update();
}

void Player::fire(){
    if(!getMissileState()){
        setMissileState(1);
        setMissileX(getXPosition()+6);
        setMissileY(getYPosition()-4);
    }
}

void Player::missileUpdate(){
    if(getMissileState()){
        setMissileY(getMissileY() - 3);
        if(getMissileY() < 0){
            setMissileY(0);
            missileDestroy();  
            return; 
        }

        #define _ 0x000000 
        #define X 0xFF0000
        int Player_sprite[21] = {
            _,X,_,
            X,X,X,
            X,X,X,
            X,X,X,
            _,_,_,
            _,_,_,
            _,_,_,
        };
        #undef _
        #undef X
        uLCD.BLIT(getMissileX(), getMissileY(), 3, 7, Player_sprite); 
    }
}

void Player::missileDestroy(){
    setMissileState(0); 
    
    #define _ 0x000000 
    int Blank_sprite[21] = {
        _,_,_,
        _,_,_,
        _,_,_,
        _,_,_,
        _,_,_,
        _,_,_,
        _,_,_,
    };
    #undef _
    uLCD.BLIT(getMissileX(), getMissileY(), 3, 7, Blank_sprite);   
}


void Player::setMissileX(int x){
    missileX = x;
}
    
void Player::setMissileY(int y){
    missileY = y;   
}    

void Player::setMissileState(int s){
    missileState = s;   
}

int Player::getMissileX(){
    return missileX;
}

int Player::getMissileY(){
    return missileY;
}

int Player::getMissileState(){
    return missileState;
}