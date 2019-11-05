#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace sf;

typedef pair<int ,int > II;

const int Height = 900;
const int Width = 900;
const int Ground = 600;

RenderWindow window(VideoMode(Height,Width) , "MilosChangesMyLife" , Style::Close | Style::Resize);

Clock realClock , createClock , rotateClock , clockStage4;
Time realTime, createTime, rotateTime , timeStage4;

const string path_RightStand        = "path/RightStand/RightStand.txt";
const string path_LeftStand         = "path/LeftStand/LeftStand.txt";
const string path_RightMove         = "path/RightMove/RightMove.txt";
const string path_LeftMove          = "path/LeftMove/LeftMove.txt";
const string path_RightJump         = "path/RightJump/RightJump.txt";
const string path_LeftJump          = "path/LeftJump/LeftJump.txt";
const string path_RightBullet       = "path/RightBullet/RightBullet.txt";
const string path_LeftBullet        = "path/LeftBullet/LeftBullet.txt";
const string path_Rocket            = "path/ricardo/ricardo.txt";
const string path_Ricardo           = "path/ricardo/bossRicardo.txt";
const string path_CircleBullet      = "path/CircleBullet/CircleBullet.txt";
const string path_RightFireBullet   = "path/RightFireBullet/RightFireBullet.txt";
const string path_LeftFireBullet    = "path/LeftFIreBullet/LeftFireBullet.txt";
const string path_UpFireBullet      = "path/UpFireBullet/UpFireBullet.txt";
const string path_DownFireBullet    = "path/DownFireBullet/DownFireBullet.txt";
const string path_ChiBaKu           = "path/ChibakuTensei/Chibaku.txt";
const string path_Thunder           = "path/Intro/thunder2/thunder2.txt";
const string path_Warning           = "path/Warning/warningLight.txt";
const string path_WarningLight      = "path/Warning/warningLight.txt";
const string path_RicardoKurama     = "path/ricardoKurama/ricardoKurama.txt";
const string path_HeathPoint        = "path/HealthPoint/HealthPoint.txt";
const string path_Background        = "path/Background2/background.txt";
const string path_Loading           = "path/Loading/Loading.txt";
const string path_Nova              = "path/Nova/Nova.txt";
const string path_RicardoIntro      = "path/RicardoIntro/RicardoIntro.txt";
const string path_Paxd              = "path/Paxd/Paxd.txt";
const string path_Angel             = "path/Angel/Angel.txt";
const string path_Block             = "path/Block/Block.txt";
