#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace sf;

class Animation{
    private:
        float speed , frame;
        Sprite sprite;              // window.draw
        vector<IntRect> frames;     // size of image
        vector<Texture> texture;    // image
    public:
        Animation(){}
        void setAnimation(string path, float speed){
            this -> speed = speed;
            frame = 0;
            ifstream fin;
            fin.open(path);
            string path_image;
            Texture tmp_texture;
            while(!fin.eof()){
                getline(fin , path_image);
                if (path_image != ""){
                    tmp_texture.loadFromFile(path_image);
                    texture.push_back(tmp_texture);
                    frames.push_back(IntRect(0,0,tmp_texture.getSize().x , tmp_texture.getSize().y));
                }
            }
            this -> sprite.setTexture(texture[0]);
            this -> sprite.setTextureRect(frames[0]);
        }
        Sprite getAnimationSprite(){
            return sprite;
        }
        void update(int x, int y){
            frame += speed;
            int n = frames.size();
            if (frame > n) frame -= float(n);
            sprite.setPosition(x,y);
            sprite.setTexture(texture[frame]);
            sprite.setTextureRect(frames[frame]);
        }
        void scaleAnimation(float x, float y){
            sprite.scale(x,y);
        }
        void rotateAnimation(float x){
            sprite.setRotation(x);
        }
        void originAnimation(float x, float y){
            sprite.setOrigin(x , y);
        }
        void setAnimationTextureRect(int x1 , int x2 , int y1 ,int y2){
            sprite.setTextureRect(IntRect(x1,x2,y1,y2));
        }
        void setPosition(int para1 , int para2){
            sprite.setPosition(para1 , para2);
        }
        void draw(){
            window.draw(sprite);
        }
        ~Animation(){
        }
};
