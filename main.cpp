//Hardware
#include "mbed.h"
#include "Speaker.h"
#include "PinDetect.h"
//Software
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    
#include <time.h>  
//Headers
#include "globals.h"
#include "Player.h"
#include "AlienAlice.h"
#include "AlienBob.h"
#include "AlienCharlie.h"
#include "AlienDonnie.h"
    
//Helper Functions
int distance(double radius, int x1, int y1, int x2, int y2);
void explosion(int x, int y);
void left_hit_callback (void);
void fire_hit_callback (void);
void right_hit_callback (void);

//Outputs
Serial pc(USBTX,USBRX);
DigitalIn left(p12);
DigitalIn fire(p13); 
DigitalIn right(p14);
Speaker mySpeaker(p21);
uLCD_4DGL uLCD(p28,p27,p29);

//Put player on outside so helper functions can access it
Player* player = new Player(65,100);

int main()
{
    //Set up pushbuttons
    left.mode(PullUp);
    fire.mode(PullUp);
    right.mode(PullUp);
    wait(.01);
    /*
    left.attach_deasserted(&left_hit_callback);
    fire.attach_deasserted(&fire_hit_callback);
    right.attach_deasserted(&right_hit_callback);
    left.setSampleFrequency();
    fire.setSampleFrequency();
    right.setSampleFrequency();
    */
    
    //Speed up uLCD rate
    uLCD.baudrate(3000000);
    wait(0.2);
    
    //Show player on map
    player->update();
    
    //Variables setup
    srand (time(NULL));
    int randNum;
    int dist;
    
    //Make the array of 6 ships, add ships to them
    Ship* enemies[6];
    Ship* enemy;
    for(int i = 0; i < 6; i++){
        //randomly choose an enemy
        randNum =  rand() % 4;
        if(randNum == 0){
            enemy = new AlienAlice(rand() % 100 + 10, 5 + 15*i);
        } else if(randNum == 1){
            enemy = new AlienBob(rand() % 100 + 10, 5 + 15*i);
        } else if(randNum == 2){
            enemy = new AlienCharlie(rand() % 100 + 10, 5 + 15*i);
        } else if(randNum == 3){
            enemy = new AlienDonnie(rand() % 100 + 10, 5 + 15*i);
        }
        //add them to the array
        enemies[i] = enemy;
        enemies[i]->update();
    }
    
    //Start Timmer
    Timer t;
    t.start();
    
    //Loop until all 6 ships are destroyed
    int kills = 6;
    while(kills){   
        //update the player missile (It will only move if it's active, will also check if it's out of bounds)
        if(!left){
            left_hit_callback();
        }
        if(!right){
            right_hit_callback();
        }
        if(!fire){
            fire_hit_callback();  
        }
        player->missileUpdate();
        wait(.005);
        //update through all 6 ships
        for(int i = 0; i < 6; i++){
            //Check if the ship is destroyed, if so, continue to the next one
            if(!enemies[i]->getDestroyed()){
                //Update it's position
                enemies[i]->update();
                wait(.005);
                //Check if the player's missile is in the field
                if(player->getMissileState()){
                    //Check if the distance between the missile and ship are close enough, if so, destroy them
                    dist = distance(6, player->getMissileX()+1, player->getMissileY(),enemies[i]->getXPosition()+7, enemies[i]->getYPosition()+4);
                    if(dist){
                        //Destroy the missile, Destroy the ship, play a noise, make an explosion, update the kill counter
                        player->missileDestroy();
                        enemies[i]->destroy();
                        mySpeaker.PlayNote(783.99,0.05,0.1);
                        wait(.05);
                        mySpeaker.PlayNote(783.99,0.05,0.1);
                        wait(.05);
                        mySpeaker.PlayNote(783.99,0.05,0.1);
                        wait(.05);
                        mySpeaker.PlayNote(622.25,0.30,0.3);
                        explosion(enemies[i]->getXPosition()+7,enemies[i]->getYPosition()+4);
                        wait(.005);
                        kills--;
                    }
                }
            }
        }
    }
    
    //Stop time, display it on the screen
    t.stop();
    uLCD.printf("\nYou Win!\nTime: %f",t.read());
    //Play a nice chord!
    mySpeaker.PlayNote(523.25,0.05,0.1);
    wait(.05);
    mySpeaker.PlayNote(587.33,0.05,0.1);
    wait(.05);
    mySpeaker.PlayNote(659.25,0.05,0.1);
    wait(.05);
    mySpeaker.PlayNote(698.46,0.05,0.1);
    wait(.05);
    mySpeaker.PlayNote(783.99,0.05,0.1);
    wait(.05);
    mySpeaker.PlayNote(880.00,0.05,0.1);
    wait(.05);
    mySpeaker.PlayNote(987.77,0.05,0.1);
    wait(.05);
    mySpeaker.PlayNote(1046.50,0.05,0.1);
    //End program
    return 0;
}

//calc dist between two points, returns true or false, used for hit detection
int distance(double radius, int x1, int y1, int x2, int y2){
    double dx = pow(x2-x1,2.0);
    double dy = pow(y2-y1,2.0);
    double dist = sqrt(dx+dy);
    if(dist < radius){
        return 1;
    }else{
        return 0;       
    }  
}

//cool explosion animation
void explosion(int x, int y){
    uLCD.circle(x,y,3,0x00FFFF);
    uLCD.circle(x,y,4,0x00FFFF);
    wait(.05);
    uLCD.circle(x,y,3,0x000000);
    uLCD.circle(x,y,4,0x000000);
    uLCD.circle(x,y,5,0xFF0066);
    uLCD.circle(x,y,6,0xFF0066);
    wait(.05);
    uLCD.circle(x,y,5,0x000000);
    uLCD.circle(x,y,6,0x000000);
    uLCD.circle(x,y,7,0xFF9933);
    uLCD.circle(x,y,8,0xFF9933);
    wait(.05);
    uLCD.circle(x,y,7,0x000000);
    uLCD.circle(x,y,8,0x000000);
    uLCD.circle(x,y,9,0xFFFF00);
    uLCD.circle(x,y,10,0xFFFF00);
    wait(.05);
    uLCD.circle(x,y,9,0x000000);
    uLCD.circle(x,y,10,0x000000);
}

//Pushbutton Subroutines
void left_hit_callback (void)
{ 
    player->move(-1);
}

void fire_hit_callback (void)
{ 
    if(!player->getMissileState()){
        player->fire();
        for(int i = 200; i < 600; i+=4){
            mySpeaker.PlayNote(i,0.005,0.1);
        }
    }
}

void right_hit_callback (void)
{
    player->move(1);   
}