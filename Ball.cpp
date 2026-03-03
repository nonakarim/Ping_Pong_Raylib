#include <iostream>
#include "raylib.h"
#include "Ball.h"

Ball::Ball(Rectangle &BallDest, float scaleX, float scaleY)
{
    BallDest.width = 50 * scaleX;
    BallDest.height = 70 * scaleY;
    BallDest.x = GetScreenWidth() /2 + BallDest.width /2;
    BallDest.y = GetScreenHeight() - BallDest.height;
}
void Ball::ball(Rectangle &BallDest, float scaleX, float scaleY)
{
    BallDest.width = sizeW * scaleX;
    BallDest.height = sizeH * scaleY;
}

void Ball::draw(Texture2D Ball, Rectangle BallSrc, Rectangle BallDest)
{
    DrawTexturePro(Ball, BallSrc, BallDest, {0, 0}, 0.0f, WHITE);
}

void Ball::update(Rectangle &BallDest, float scaleX, float scaleY)
{
    BallDest.x += speedX * scaleX * GetFrameTime();
    BallDest.y += speedY * scaleY * GetFrameTime();
}

void Ball::collision(Rectangle &BallDest, Rectangle Paddle1, Rectangle Paddle2, int &score1, int &score2, Sound hit, bool &win, bool &lose)
{

    if (BallDest.x + BallDest.width >= GetScreenWidth() || BallDest.x <= 0) 
    {
        PlaySound(hit);

        if(BallDest.x + BallDest.width >= GetScreenWidth())
        {
            score2 ++;
            sizeW -= 18;
            sizeH -= 18;         
        }
        if(BallDest.x <= 0)
        {
            score1 ++;
        }

        if(score2 == 3)
        {
            win = true;
            sizeH = 70;
            sizeW = 50;
        }
        else if(score1 == 3)
        {
            lose = true;
        }

        BallDest.x = GetScreenWidth() /2 + BallDest.width /2;
        BallDest.y = GetScreenHeight() - BallDest.height;
    }
    if(BallDest.y + BallDest.height >= GetScreenHeight())
    {
        PlaySound(hit);

        BallDest.y = GetScreenHeight() - BallDest.height; 
        speedY *= -1;
    }
    else if(BallDest.y <= 0)
    {
        PlaySound(hit);

        BallDest.y = 0; 
        speedY *= -1;
    }


    if (CheckCollisionRecs(BallDest, Paddle1))
    {
        PlaySound(hit);

        BallDest.x = Paddle1.x - BallDest.width;
        speedX *= -1;
    }
    else if (CheckCollisionRecs(BallDest, Paddle2))
    {
        PlaySound(hit);

        BallDest.x = Paddle2.x + Paddle2.width;
        speedX *= -1;
    }
}
