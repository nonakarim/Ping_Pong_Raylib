#include<iostream>
#include "raylib.h"

class Ball{
private:
int speedX = 300;
int speedY = 300;
int sizeW=50;
int sizeH = 70;
public:
    Ball(Rectangle &BallDest, float scaleX, float scaleY);
    void ball(Rectangle &BallDest, float scaleX, float scaleY);

    void draw(Texture2D Ball, Rectangle BallSrc, Rectangle BallDest);

    void update(Rectangle &BallDest, float scaleX, float scaleY);

    void collision(Rectangle &BallDest, Rectangle Paddle1, Rectangle Paddle2, int &score1, int &score2, Sound hit, bool &win, bool &lose);
};