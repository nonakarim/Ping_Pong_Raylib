#include <iostream>
#include "raylib.h"
#include "Paddles.h"

Paddle1::Paddle1(Rectangle &paddleDest, float scaleX, float scaleY){
    paddleDest.width = 50 * scaleX;
    paddleDest.height = 110 * scaleY;
    paddleDest.x = GetScreenWidth() - paddleDest.width - 50;
    paddleDest.y = GetScreenHeight() /2 - paddleDest.height /2;
}
void Paddle1::paddle(Rectangle &paddleDest, float scaleX, float scaleY)
{
    paddleDest.width = 50 * scaleX;
    paddleDest.height = 110 * scaleY;
    paddleDest.x = GetScreenWidth() - paddleDest.width - 50;
}

void Paddle1::draw(Texture2D paddle, Rectangle paddleSrc, Rectangle paddleDest)
{
        DrawTexturePro(paddle, paddleSrc, paddleDest, {0, 0}, 0.0f, WHITE);
}

void Paddle1::move(Rectangle &paddleDest, Rectangle ballDest)
{
    float paddleCenter = paddleDest.y + paddleDest.height / 2;
    float ballCenter   = ballDest.y + ballDest.height / 2;

    if(paddleCenter < ballCenter)
    {
        paddleDest.y += 200 * GetFrameTime();
    }
    else if(paddleCenter > ballCenter)
    {
        paddleDest.y -= 200 * GetFrameTime();
    }

    if(paddleDest.y < 0)
        paddleDest.y = 0;

    if(paddleDest.y + paddleDest.height > GetScreenHeight())
        paddleDest.y = GetScreenHeight() - paddleDest.height;

}
Paddle2::Paddle2(Rectangle &Paddle2Dest, float scaleX, float scaleY)
{
    Paddle2Dest.width = 50 * scaleX;
    Paddle2Dest.height = 110 * scaleY;
    Paddle2Dest.x = 50;
    Paddle2Dest.y = GetScreenHeight()/2 - Paddle2Dest.height/2;
}
void Paddle2::paddle(Rectangle &paddleDest, float scaleX, float scaleY)
{
    paddleDest.width = 50 * scaleX;
    paddleDest.height = 110 * scaleY;
}

void Paddle2::draw(Texture2D paddle, Rectangle paddleSrc, Rectangle paddleDest, bool win, Sound winning)
{
    if(!win)
        DrawTexturePro(paddle, paddleSrc, paddleDest, {0, 0}, 0.0f, WHITE);
    else
    {
        DrawTexturePro(paddle, paddleSrc, paddleDest, {0, 0}, 0.0f, GREEN);
        PlaySound(winning);
    }  
}

void Paddle2::move(Rectangle &paddleDest, bool mouse, bool keyboard)
{
    if(keyboard)
    {
        if(IsKeyDown(KEY_W) && paddleDest.y >= 0)
        {
            paddleDest.y -= 300 * GetFrameTime();
        }
        if(IsKeyDown(KEY_S) && paddleDest.y + paddleDest.height < GetScreenHeight())
        {
            paddleDest.y += 300 * GetFrameTime();
        }
    }
    else
    {
            paddleDest.y = GetMousePosition().y;

    }
}
