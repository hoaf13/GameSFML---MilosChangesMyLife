#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace sf;

class Boss{
    private:
        int x;
        int y;
        int direction;  //0.phai    1.trai
        int stage;
        Animation animation;
    public:
        friend class CircleBullet;
        friend class Warning;
        Boss(){
            stage = 1;
            x = 200;
            y = 0;
            direction = 0;
            animation.setAnimation(path_Ricardo,0.01f);
            animation.scaleAnimation(0.5,0.5);
        }
        void setAnimation(string path , float speed){
            animation.setAnimation(path, speed);
        }
        II getBossPos(){
            return make_pair(x,y);
        }
        void setBossPos(int x ,int y){
            this->x = x;
            this->y = y;
        }
        int getBossDir(){
            return direction;
        }
        void setBossDir(int para){
            direction = para;
        }
        int getBossSta(){
            return stage;
        }
        void setBossSta(int para){
            stage = para;
        }
        void update(){
            if (stage == 1){
                if (x > 750) direction = 1;
                if (x < -50) direction = 0;
                if (direction == 0) x+=4;
                else x-=4;
            }
            if (stage == 2){
                int X = rand()%(Width-200);
                int Y = rand()%150;
                x = X;
                y = Y;
            }

        }
        void draw(){
            animation.update(x,y);
            animation.draw();
        }
};
Boss ricardo;
