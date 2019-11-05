#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "hero.h"

using namespace std;
using namespace sf;

class Thunder{
    private:
        int x;
        int y;
        Animation animation;
    public:
        Thunder(){
            x = 250;
            y = 600-52;
            animation.setAnimation(path_Thunder,0.09f);
            //animation.scaleAnimation(2.0f,2.0f);
        }
        void update(){
            animation.update(x+10,y-46);
        }
        void draw(){
            animation.draw();
        }
};

class Warning{
    private:
        int x;
        int y;
        Animation animation;
    public:
        Warning(){
            x = 345;
            y = 450;
            animation.setAnimation(path_Warning,0.1f);
        }
        II getWarningPos(){
            return make_pair(x,y);
        }
        void setWarningPos(int x, int y){
            this-> x = x;
            this-> y = y;
        }
        void setWarningSca(float para1 , float para2){
            animation.scaleAnimation(para1 , para2);
        }
        void update(){
            animation.update(x,y);
        }
        void draw(){
            animation.draw();
        }
};

class Angel{
    private:
        int x;
        int y;
        Animation animation;
    public:
        Angel(){

            animation.setAnimation(path_Angel,0.1f);
        }
        void setAngelPos(int x , int y){
            this->x=x;
            this->y=y;
        }
        void update(){
            animation.update(x,y);
        }
        void draw(){
            animation.draw();
        }
};
Angel angel;

class RicardoKurama{
    private:
        int x;
        int y;
        Animation animation;
    public:
        RicardoKurama(){
            x = 0;
            y = 200;
            animation.scaleAnimation(3.4f,3.4f);
            animation.setAnimation(path_RicardoKurama, 0.1f);
        }
        II getRicardoKuramaPos(){
            return make_pair(x,y);
        }
        void setRicardoKuramaPos(int x, int y){
            this->x = x;
            this->y = y;
        }
        void update(){

        }
        void draw(){
            animation.update(x,y);
            animation.draw();
        }
};

class Nova{
    private:
        int x;
        int y;
        Animation animation;
    public:
        Nova(){
            animation.setAnimation(path_Nova,0.07f);
        }
        void update(){
            animation.update(x,y);
        }
        void draw(){
            animation.draw();
        }
};

class HealthPoint{
    private:
        int x;
        int y;
        Animation animation;
    public:
        HealthPoint(){
            animation.setAnimation(path_HeathPoint,0.1f);
            animation.scaleAnimation(0.4f,0.4f);
        }
        II getHealthPointPos(){
            return make_pair(x,y);
        }
        void setHealthPointPos(int x ,int y){
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
vector<HealthPoint> healthPoint(3);


Thunder thunder;
Warning warning;
RicardoKurama ricardoKurama;
Nova nova;
