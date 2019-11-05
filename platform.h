#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "animation.h"

using namespace std;
using namespace sf;


class Background{
    private:
        int x;
        int y;
        Animation animation;
    public:
        Background(){
            animation.setAnimation(path_Background,0.1f);
        }
        II getBackgroundPos(){
            return make_pair(x,y);
        }
        void setBackgroundPos(int x, int y){
            this->x = x;
            this->y = y;
        }
        void update(){
            animation.update(x,y);
        }
        void draw(){
            animation.draw();
        }
};
Background background;

class Groundz{
    private:
        int x1, x2;
        int y;
    public:
        Groundz(){}
        void setGroundzPos(int x1 , int x2, int y){
            this->x1 = x1;
            this->x2 = x2;
            this->y = y;
        }
        II getGroundzPosX(){
            return make_pair(x1,x2);
        }
        int getGroundzPosY(){
            return y;
        }
};
Groundz groundz[5];

class Block{
    private:
        int x;
        int y;
        Animation animation;
    public:
        Block(){
            animation.setAnimation(path_Block,0.1f);
            animation.scaleAnimation(0.1f,0.1f);
        }
        void setBlockPos(int x, int y){
            this -> x = x;
            this -> y = y;
            animation.setPosition(this->x,this->y);
        }
        II getBlockPos(){
            return make_pair(x,y);
        }
        void update(){
            animation.update(x,y);
        }
        void draw(){
            animation.draw();
        }
};
vector<Block> blocks(Width);
