#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace sf;

class Paxd{
    private:
        int x;
        int y;
        Animation animation;
    public:
        Paxd(){
            x = 400;
            y = 550;
            animation.setAnimation(path_Paxd, 0.1f);
            animation.scaleAnimation(1.5f,1.5f);
        }
        void update(){
            animation.update(x,y);
        }
        void draw(){
            animation.draw();
        }
};
Paxd paxd;
