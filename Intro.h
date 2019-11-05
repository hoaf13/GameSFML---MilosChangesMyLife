#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace sf;

class Loading{
    private:
        int x;
        int y;
        Animation animation;
    public:
        Loading(){
            animation.setAnimation(path_Loading,0.12f);
        }
        ~Loading(){}
        void update(){
            animation.update(x,y);
        }
        void draw(){
            animation.draw();
        }
};
Loading loading;

class RicardoIntro{
    private:
        int x;
        int y;
        Animation animation;
    public:
        RicardoIntro(){
            animation.setAnimation(path_RicardoIntro,0.1f);
        }
        void update(){
            animation.update(x,y);
        }
        void draw(){
            animation.draw();
        }
};
RicardoIntro ricardoIntro;
