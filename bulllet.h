#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace sf;

Clock createFireBulletClock , createCircleBulletClock;
Time createFireBulletTime, createCircleBulletTime;

Clock c1;
Time t1;

class Bullet{
    private:
        int x;
        int y;
        int direction;
        Animation animation;
    public:
        Bullet(int x, int y , int direction){
            this->x = x;
            this->y = y;
            this->direction = direction;
            animation.setAnimation(path_Rocket , 0.04f);
        }
        II getBulletPos(){
            return make_pair(x,y);
        }
        void setBulletPos(int x, int y){
            this->x = x;
            this->y = y;
        }
        int getBulletDir(){
            return direction;
        }
        void setBulletDir(int para){
            direction = para;
        }
        void setBulletScale(float para1 , float para2){
            animation.scaleAnimation(para1 , para2);
        }
        Sprite getSprite(){
            return animation.getAnimationSprite();
        }
        void setBulletRot(float para){
            animation.rotateAnimation(para);
        }
        void setBulletOri(int para1 , int para2){
            animation.originAnimation(para1,para2);
        }
        void draw(){
            animation.update(x,y);
            animation.draw();
        }
};

class CircleBullet{
    private:
        int x;
        int y;
        double angle;
        double r;
        Animation animation;
    public:
        CircleBullet(double angle, double r){
            x = ricardo.getBossPos().first + 150;
            y = ricardo.getBossPos().second+ 200;
            this-> angle = angle;
            this-> r = r;
            animation.scaleAnimation(0.5,0.5);
            animation.setAnimation(path_CircleBullet , 0.1f);
        }

        II getCircleBulletPos(){
            return make_pair(x,y);
        }
        void setCircleBulletPos(int para1 ,int para2){
            this->x = para1;
            this->y = para2;
        }
        void update(){
            srand(time(NULL));
            int shape[] = {20,10,12,25,23,21,19};
            int indez = rand()%7;
            x += int(cos(angle) * r)/shape[indez];
            y += int(sin(angle) * r)/shape[indez];
        }
        void draw(){
            animation.update(x,y);
            animation.draw();
        }
};

class FireBullet{
    private:
        int x;
        int y;
        int direction;  // 0.phai   1.trai  2.len   3.xuong
        Animation animation;
    public:
        FireBullet(int x , int y , int direction){
            this->x = x;
            this->y = y;
            this->direction = direction;
            if (direction == 0) animation.setAnimation(path_RightFireBullet,0.2f);
            if (direction == 1) animation.setAnimation(path_LeftFireBullet,0.2f);
            if (direction == 2) animation.setAnimation(path_UpFireBullet,0.2f);
            if (direction == 3) animation.setAnimation(path_DownFireBullet,0.2f);
            animation.scaleAnimation(0.5f,0.5f);
        }
        II getFireBulletPos(){
            return make_pair(x,y);
        }
        void setFireBulletPos(int x , int y){
            this->x = x;
            this->y = y;
        }
        int getFireBulletDir(){
            return direction;
        }
        void setFireBulletDir(int para){
            direction = para;
        }
        void update(){
            if (direction == 0){
                x += 4;
            }
            if (direction == 1){
                x -= 4;
            }
            if (direction == 2){
                y -= 4;
            }
            if (direction == 3){
                y += 4;
            }
        }
        void draw(){
            animation.update(x,y);
            animation.draw();
        }
};

class Chibaku{
    private:
        int x;
        int y;
        Animation animation;
    public:
        Chibaku(){
            animation.setAnimation(path_ChiBaKu, 0.5f);
            animation.scaleAnimation(1.8f,1.8f);
        }
        ~Chibaku(){}
        II getChibakuPos(){
            return make_pair(x,y);
        }
        void setChibakuPos(int x , int y){
            this->x = x;
            this->y = y;
        }
        void update(){
            t1 = c1.getElapsedTime();
            int k = t1.asSeconds();
            k /= 18;
            y += k;
        }
        void draw(){

            animation.update(x,y);
            animation.draw();
        }
};
Chibaku chibaku;

vector<Bullet> bullets;
vector<CircleBullet> circlebullets;
vector<FireBullet> firebullets;


void createBullet(){
    createTime = createClock.getElapsedTime();
    if (createTime >= seconds(0.07f)){
        int X = ricardo.getBossPos().first + 120 + rand()%100 - 50;
        Bullet bullet(X, 80 , 2);
        bullet.setBulletScale(0.8 , 0.8);
        bullets.push_back(bullet);
        createClock.restart();
    }
}

void updateBullet(){
    rotateTime = rotateClock.getElapsedTime();
    for(int i=0;i<bullets.size();i++){
        if (bullets[i].getBulletDir() == 0) bullets[i].setBulletPos(bullets[i].getBulletPos().first + 4 , bullets[i].getBulletPos().second );
        if (bullets[i].getBulletDir() == 1) bullets[i].setBulletPos(bullets[i].getBulletPos().first - 4 , bullets[i].getBulletPos().second );
        if (bullets[i].getBulletDir() == 2) bullets[i].setBulletPos(bullets[i].getBulletPos().first  , bullets[i].getBulletPos().second + 4 );
        if (bullets[i].getBulletDir() == 3) bullets[i].setBulletPos(bullets[i].getBulletPos().first  , bullets[i].getBulletPos().second - 4);
    }
    while(1){
        int indez = -1;
        for(int i=0;i<bullets.size();i++){
            int X = bullets[i].getBulletPos().first;
            int Y = bullets[i].getBulletPos().second;
            if (X < 0 || X > Width || Y < 0 || Y > Height){
                indez = i;
                break;
            }
        }
        if (indez == -1) break;
        bullets.erase(bullets.begin() + indez , bullets.begin() + indez + 1);
    }
}

void drawBullet(){
    for(int i=0;i<bullets.size();i++){
        bullets[i].draw();
    }
}

void createCircleBullet(int cnt){
    for(int i=2;i<=cnt;i++){
        CircleBullet circlebullet(double((360/cnt)*i) , 50);
        circlebullets.push_back(circlebullet);
    }
}

void updateCircleBullet(){
    for(int i=0;i<circlebullets.size();i++){
        circlebullets[i].update();
    }
    while(1){
        int indez = -1;
        for(int i=0;i<circlebullets.size();i++){
            int X = circlebullets[i].getCircleBulletPos().first;
            int Y = circlebullets[i].getCircleBulletPos().second;
            if (X < 0 || X > Width || Y < 0 || Y > Height ){
                 indez = i;
                 break;
            }
        }
        if (indez == -1) return;
        circlebullets.erase(circlebullets.begin()+indez , circlebullets.begin()+indez+1);
    }
}

void drawCircleBullet(){
    for(int i=0;i<circlebullets.size();i++){
        circlebullets[i].draw();
    }
}

void createFireBullet(int direction){
    if (direction == 0){
        direction = rand()%2;
        if (direction == 0){
            FireBullet firebullet(0,Ground-50,direction);
            firebullets.push_back(firebullet);
        }
        else{
            FireBullet firebullet(Width,Ground-50,direction);
            firebullets.push_back(firebullet);
        }
    }
    if (direction == 2){
        for(int i=1;i<20;i+=2){
            FireBullet firebullet(i*int(Width/20),Height,2);
            firebullets.push_back(firebullet);
        }
        for(int i=0;i<20;i+=2){
            FireBullet firebullet(i*int(Width/20),0,3);
            firebullets.push_back(firebullet);
        }
    }
}

void updateFireBullet(){
    for(int i=0;i<firebullets.size();i++){
        firebullets[i].update();
    }
    while(1){
        int indez = -1;
        for(int i=0;i<firebullets.size();i++){
            int X = firebullets[i].getFireBulletPos().first;
            int Y = firebullets[i].getFireBulletPos().second;
            if (X < 0 || X > Width || Y < 0 || Y > Height){
                indez = i;
            }
        }
        if (indez == -1) break;
        else{
            firebullets.erase(firebullets.begin() + indez , firebullets.begin() + indez + 1);
        }
    }
}

void drawFireBullet(){
    for(int i=0;i<firebullets.size();i++){
        firebullets[i].draw();
    }
}
