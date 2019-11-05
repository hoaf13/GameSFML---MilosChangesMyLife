#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>

#include "constant.h"
#include "platform.h"
#include "hero.h"
#include "boss.h"
#include "bulllet.h"
#include "effect.h"
#include "animation.h"
#include "Intro.h"
#include "Outro.h"


using namespace std;
using namespace sf;

int stage = 0;
bool isPreparing = true;
bool isEnding = false;
Font font;
long long PLAYERPOINT = 0;
Music music;
Music taju;
Music shinra;
bool flagTaju = true;
bool flagShinra = true;

string numToString(long long n){
    string ans;
    stringstream ss;
    ss << n;
    ss >> ans;
    return ans;
}

void processCollision(){
    if (hero.getHeroIsUndead() == true){
        return ;
    }
    int X = hero.getHeroPos().first;
    int Y = hero.getHeroPos().second;

    for(int i=0;i<bullets.size();i++){
        int a = bullets[i].getBulletPos().first;
        int b = bullets[i].getBulletPos().second;
        for(int j=X; j <= X + 50 ;j++ ){
            for(int k= Y - 20 ; k <= Y + 0 ; k++){
                if (j == a && k == b){
                    hero.setHeroAlive(false);
                    return;
                }
            }
        }
    }

    for(int i=0;i<circlebullets.size();i++){
        int a = circlebullets[i].getCircleBulletPos().first;
        int b = circlebullets[i].getCircleBulletPos().second;
        for(int j=X; j <= X + 50 ;j++ ){
            for(int k= Y - 20 ; k <= Y + 0 ; k++){
                if (j == a && k == b){
                    hero.setHeroAlive(false);
                    return;
                }
            }
        }
    }

    for(int i=0;i<firebullets.size();i++){
        int a = firebullets[i].getFireBulletPos().first;
        int b = firebullets[i].getFireBulletPos().second;
        if (firebullets[i].getFireBulletDir() == 0) a += 80 , b += 40;
        if (firebullets[i].getFireBulletDir() == 1) a += 0 ,  b += 40;
        if (firebullets[i].getFireBulletDir() == 2) a += 20 , b += 0;
        if (firebullets[i].getFireBulletDir() == 3) a += 20 , b += 70;

        for(int j=X; j <= X + 50 ;j++ ){
            for(int k= Y - 20 ; k <= Y + 0 ; k++){
                if (j == a && k == b){
                    hero.setHeroAlive(false);
                    return;
                }
            }
        }
    }
}

void INIT(){
    srand(time(NULL));
    realClock.restart();
    font.loadFromFile("/home/hoaf13/workspace/SFMLtutorial/aachenb.ttf");
    music.openFromFile("path/musicduring.wav");
    music.setVolume(10);
    music.play();

    taju.openFromFile("path/taju.wav");
    shinra.openFromFile("path/shinra.wav");
    /*------------------------- PLATFORM ----------------------*/

    for(int i=0;i<Width;i+=20){
        blocks[i].setBlockPos(i,Ground+50);
    }
    Block block[4];
    block[0].setBlockPos(100,550);
    block[1].setBlockPos(Width - 100,550);
    block[2].setBlockPos(50,450);
    block[3].setBlockPos(Width - 50,450);
    for(int i=0;i<4;i++) blocks.push_back(block[i]);
    groundz[0].setGroundzPos(135,660,600);
    groundz[1].setGroundzPos(40,80,500);
    groundz[2].setGroundzPos(Width - 160 ,Width - 120 , 500);
    groundz[3].setGroundzPos( -10 ,30 ,400);
    groundz[4].setGroundzPos( Width - 110 , Width - 70 ,400);
    healthPoint[0].setHealthPointPos(700,800);
    healthPoint[1].setHealthPointPos(750,800);
    healthPoint[2].setHealthPointPos(800,800);

    ricardo.setAnimation(path_Ricardo,0.4f);
    ricardo.setBossSta(1);
    chibaku.setChibakuPos(280,-20);

}

void PREPROCESSING(){
    processCollision();
    hero.processDeath();
    hero.OutOfOder();
    hero.gravityFall();
    hero.gravityJump();
}

void EVENTPROCESSING(){
    if (hero.getHeroLife() == 0){
        isEnding = true;
    }
    if (stage != 0){
        if (Keyboard::isKeyPressed(Keyboard::A)) hero.moveLeft();
        if (Keyboard::isKeyPressed(Keyboard::D)) hero.moveRight();
        if (Keyboard::isKeyPressed(Keyboard::W)) hero.jump();
    }
}

void UPDATE(){
    background.update();
    if (stage != 1){
        bullets.erase(bullets.begin(),bullets.end());
    }
    if (stage != 2){
        firebullets.erase(firebullets.begin(),firebullets.end());
    }
    if (stage != 3){
        circlebullets.erase(circlebullets.begin(), circlebullets.end());
    }
}

void DRAWPLATFORM(){
        if (stage != 0 && stage != 4) background.draw();
        for(int i=200;i<700;i+=20){
            blocks[i].update();
            blocks[i].draw();
        }
        for(int i=blocks.size()-1;i>=blocks.size()-4;i--){
            blocks[i].update();
            blocks[i].draw();
        }
        PLAYERPOINT = int(realTime.asSeconds());
        Text text( "POINT: " + numToString(PLAYERPOINT),font);
        window.draw(text);

        while (healthPoint.size() > hero.getHeroLife()) healthPoint.erase(healthPoint.begin(),healthPoint.begin()+1);
        for(int i=0;i<hero.getHeroLife();i++){
            healthPoint[i].update();
        }

        for(int i=0;i<hero.getHeroLife();i++){
            healthPoint[i].draw();
        }

}

/* ------------- STAGE 0 -------------*/
void STAGE0(){
    /* update */
    warning.update();
    thunder.update();
    /*draw*/
    realTime = realClock.getElapsedTime();
    if (realTime.asSeconds() < 6.0f){
        if (realTime.asSeconds() <4.0f) thunder.draw();
        warning.draw();
    }else{
        if (realTime.asSeconds() < 5.0f) warning.draw();
    }
}

/* ------------- STAGE 1 ------------- */
void STAGE1(){
    /* update */
        ricardo.update();
        realTime = realClock.getElapsedTime();
        if (realTime.asSeconds() < 25.0f) createBullet();
        else{
            int k = realTime.asSeconds();
            if (k % 2 == 0) warning.setWarningPos( 800 , 600);
            else warning.setWarningPos( 50 , 600);
            warning.setWarningSca(1.002f,1.002f);
            warning.update();
            warning.draw();
        }
        updateBullet();
    /* draw */

        ricardo.draw();
        drawBullet();
}

/* ------------- STAGE 2 ------------- */
int timesCreateUpDownFireBall = 1;
Time timeCreateUpDownFireBall;
Clock clockCreateUpDownFireBall;
void STAGE2(){
    /* update */
    createTime = createClock.getElapsedTime();
    if (createTime.asSeconds() > 0.9f){
        createFireBullet(0);
        createClock.restart();
    }
    timeCreateUpDownFireBall = clockCreateUpDownFireBall.getElapsedTime();
    if (timeCreateUpDownFireBall.asSeconds() > 3.0f){
            timesCreateUpDownFireBall = 1;
            clockCreateUpDownFireBall.restart();
    }
    for(int i=1;i<5;i++){
        int X = hero.getHeroPos().first;
        int Y = hero.getHeroPos().second;
        int x1 = groundz[i].getGroundzPosX().first;
        int x2 = groundz[i].getGroundzPosX().second;
        int y = groundz[i].getGroundzPosY();
        if (X > x1 && X < x2 && Y == y && timesCreateUpDownFireBall > 0 ){
            createFireBullet(2);
            createFireBullet(3);
            timesCreateUpDownFireBall--;
        }
    }
    updateFireBullet();
    /* draw */
    drawFireBullet();
}

/* ------------- STAGE 3 ------------- */
int timesCreateCircleBullet = 1;
Time timeCreateCircleBullet;
Clock clockCreateCircleBullet;
void STAGE3(){
    /* update */
    ricardo.setBossSta(2);
    timeCreateCircleBullet = clockCreateCircleBullet.getElapsedTime();
    if (timeCreateCircleBullet.asSeconds() > 2.5f){
        clockCreateCircleBullet.restart();
        ricardo.update();
        timesCreateCircleBullet = 1;
    }
    else{
        if (timeCreateCircleBullet.asSeconds() > 1.5f && timesCreateCircleBullet > 0){
            createCircleBullet(60);
            timesCreateCircleBullet--;
        }
    }
    updateCircleBullet();
    /*draw*/
    ricardo.draw();
    drawCircleBullet();
    clockStage4.restart();
}

/* ------------- STAGE 4 ------------- */
void STAGE4(){
        timeStage4 = clockStage4.getElapsedTime();
        if (timeStage4.asSeconds() < 7.1f){
            ricardoKurama.update();
            ricardoKurama.draw();
            for(int i=200;i<700;i+=20){
                blocks[i].draw();
            }
            for(int i=blocks.size()-1;i>=blocks.size()-4;i--){
                blocks[i].draw();
            }
        }
        else{
            chibaku.update();
            chibaku.draw();
        }
        /*-----------------*/
        realTime = realClock.getElapsedTime();
        if (realTime.asSeconds() > 88.0f && realTime.asSeconds() < 90.0f){
            nova.update();
            nova.draw();
        }

}

int main(){

    window.setFramerateLimit(120);
    INIT();
    while(window.isOpen()){
        Event event;

        while(window.pollEvent(event)){
            if (event.type == Event::Closed) window.close();
        }
        window.clear();
        if (isEnding){
            music.stop();
            if(flagShinra){
               flagShinra = false;
               shinra.setVolume(50);
               shinra.play();
            }
            paxd.update();
            paxd.draw();
            Text text( "YOUR CURRENT POINT: " + numToString(PLAYERPOINT),font);
            if (PLAYERPOINT == 90){
                Text text2 ("GOOD JOB !!! YOU ARE THE BEST PLAYER :))" , font);
                text2.setPosition(0,200);
                window.draw(text2);
            }
            window.draw(text);
        }
        else{
            if (isPreparing){
                realTime = realClock.getElapsedTime();
                if (realTime.asSeconds() < 5.5f){
                    loading.update();
                    loading.draw();
                }else{
                    ricardoIntro.update();
                    ricardoIntro.draw();
                }
                if (Keyboard::isKeyPressed(Keyboard::Enter)){
                    realClock.restart();
                    isPreparing = false;
                }
            }else{
                PREPROCESSING();
                EVENTPROCESSING();
                UPDATE();
                DRAWPLATFORM();
                realTime = realClock.getElapsedTime();

                if (realTime.asSeconds() < 6.0f) stage = 0;
                if (realTime.asSeconds() >= 6.0f && realTime.asSeconds() < 30.0f) stage = 1;
                if (realTime.asSeconds() >= 30.0f && realTime.asSeconds() < 60.0f) stage = 2;
                if (realTime.asSeconds() >= 60.0f && realTime.asSeconds() < 80.0f) stage = 3;
                if (realTime.asSeconds() >= 80.0f && realTime.asSeconds() < 100.0f) stage = 4;

                if (stage == 0) STAGE0();
                if (stage == 1) STAGE1();
                if (stage == 2) STAGE2();
                if (stage == 3) STAGE3();
                if (stage == 4) STAGE4();
                if (realTime.asSeconds() > 5.0f && realTime.asSeconds() < 87.0f) hero.draw();
                if (hero.getHeroIsUndead()){
                    angel.setAngelPos(hero.getHeroPos().first+30,hero.getHeroPos().second-30);
                    angel.update();
                    if (realTime.asSeconds() > 5.0f) angel.draw();
                }
                if (realTime.asSeconds() > 90.0f) hero.setHeroLife(0);
                if (realTime.asSeconds() > 81.0f){
                    if(flagTaju){
                        flagTaju = false;
                        taju.play();
                    }
                    music.stop();
                }
                if (realTime.asSeconds() > 85.0f){
                    if(flagShinra){
                        flagShinra = false;
                        shinra.setVolume(50);
                        shinra.play();
                    }
                }
            }
        }
        window.display();
    }
return 0;
}
