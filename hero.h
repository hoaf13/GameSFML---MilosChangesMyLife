#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "effect.h"

using namespace std;
using namespace sf;

class Hero{
    private:
        int x;
        int y;
        int height;
        int direction;
        int life;
        bool alive;
        bool wanaJump;
        float acceleration;
        bool isUndead;
        Music music;
        bool isPlaymusic;
        Clock clock;
        Time time;
        Animation animation[6]; // 0.RightStand 1.LeftStand  2.RightMove 3.LeftMove  4.RightJump   5.LeftJump
    public:
        friend class HealthPoint;
        friend class Angel;
        Hero(){
            acceleration = 2;
            x = 200;
            y = 600;
            life = 4;
            isPlaymusic = false;
            wanaJump = false;
            isUndead = false;
            animation[0].scaleAnimation(1.0f,0.7f);
            animation[1].scaleAnimation(1.0f,0.7f);
            animation[2].scaleAnimation(1.0f,0.7f);
            animation[3].scaleAnimation(1.0f,0.7f);
            animation[4].scaleAnimation(1.0f,0.7f);
            animation[5].scaleAnimation(1.0f,0.7f);
            animation[0].setAnimation(path_RightStand , 0.009f);
            animation[1].setAnimation(path_LeftStand, 0.009f);
            animation[2].setAnimation(path_RightMove,0.3f);
            animation[3].setAnimation(path_LeftMove,0.3f);
            animation[4].setAnimation(path_RightJump,0.04f);
            animation[5].setAnimation(path_LeftJump,0.04f);
        }
        bool getHeroIsUndead(){
            return isUndead;
        }
        void setHeroIsUndead(bool para){
            isUndead = para;
        }
        bool getHeroAlive(){
            return alive;
        }
        void setHeroAlive(bool x){
            alive = x;
        }
        int getHeroDirection(){
            return direction;
        }
        void setHeroDirection(int para){
            direction = para;
        }
        int getHeroLife(){
            return life;
        }
        void setHeroLife(int para){
            life = para;
        }
        void setHeroPos(int x, int y){
            this -> x = x;
            this -> y = y;
        }
        II getHeroPos(){
            return make_pair(x,y);
        }
        void processDeath(){
            if (y > Height) alive = false;
            if (alive == false){
                music.openFromFile("path/die.wav");
                music.setVolume(100);
                music.play();
                wanaJump = false;
                direction = 0;
                setHeroPos(300,450);
                alive = true;
                life--;
                isUndead = true;
                clock.restart();
            }
            time = clock.getElapsedTime();
                if (time.asSeconds() > 2.0f && isUndead){
                isUndead = false;
            }
        }
        bool isReactBlock(){
            for(int i=0;i<5;i++){
                int Y = groundz[i].getGroundzPosY();
                int X1 = groundz[i].getGroundzPosX().first;
                int X2 = groundz[i].getGroundzPosX().second;
                if (y > Y && y < Y+100 && x > X1 && x < X2) return true;
            }
            return false;
        }
        void OutOfOder(){
            if (x < 0) x = Width;
            if (x > Width) x = 0;
        }

        void gravityFall(){

            bool isFall =  true;
            if (wanaJump == false){
                for(int i=0;i<5;i++){
                    int X1 = groundz[i].getGroundzPosX().first;
                    int X2 = groundz[i].getGroundzPosX().second;
                    int Y = groundz[i].getGroundzPosY();
                    if ( ( x > X1 && x < X2 && y >= Y && y <= Y + 20) ){
                        isFall = false;
                        y = groundz[i].getGroundzPosY();

                    }
                }
             }

            if (isFall){
                y = y + acceleration*1.5;
            }
        }
        void gravityJump(){
            if (getHeroPos().second < height) wanaJump = false;
            if (wanaJump){
                setHeroPos(getHeroPos().first , getHeroPos().second - 6);
            }
        }
        Sprite getSprite(){
            return animation[direction].getAnimationSprite();
        }
    /* Activities */

        void moveRight(){
            direction = 2;
            if (isReactBlock() == false) setHeroPos(getHeroPos().first + 2 ,getHeroPos().second);
        }
        void moveLeft(){
            direction = 3;
            if (isReactBlock() == false) setHeroPos(getHeroPos().first - 2 ,getHeroPos().second);

        }
        void jump(){

            for(int i=0;i<5;i++){
                int X1 = groundz[i].getGroundzPosX().first;
                int X2 = groundz[i].getGroundzPosX().second;
                int Y = groundz[i].getGroundzPosY();
                if (x > X1 && x < X2 && y == Y) wanaJump = true, isPlaymusic = false;
            }
            if (y == groundz[0].getGroundzPosY()) height = 450;
            if (y == groundz[1].getGroundzPosY()) height = 350;
            if (y == groundz[3].getGroundzPosY()) height = 250;
            if ((direction == 2 || direction == 0)) direction = 4;
            if ((direction == 1 || direction == 3)) direction = 5;
            if (isPlaymusic == false){
                music.openFromFile("path/jump.wav");
                music.setVolume(10);
                music.play();

                isPlaymusic = true;
            }

        }
    /*--------------------*/
        void draw(){
           bool isFall = true;
            for(int i=0;i<5;i++){
                int X1 = groundz[i].getGroundzPosX().first;
                int X2 = groundz[i].getGroundzPosX().second;
                int Y = groundz[i].getGroundzPosY();
                if (y == Y && x > X1 && x < X2) isFall = false;
            }
            if (isFall == false && direction == 4) direction = 0;
            if (isFall == false && direction == 5) direction = 1;
            if (direction == 2 && isFall) direction = 4;
            if (direction == 3 && isFall) direction = 5;
            animation[direction].update(x,y-40);
            animation[direction].draw();
            if (direction % 2 == 0 && direction != 4) direction = 0;
            if ( direction % 2 == 1 && direction != 5) direction = 1;
        }
};
Hero hero;
