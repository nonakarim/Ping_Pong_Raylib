#include <iostream>
#include "raylib.h"
#include "menu.h"

void Menu::start(Rectangle &dest, float scaleX, float scaleY)
{
        dest.width = 283*scaleX;
        dest.height = 114*scaleY;
        dest.x = GetScreenWidth()/2 - dest.width/2;
        dest.y = GetScreenHeight()/4 - dest.height/4;
}
void Menu::stop(Rectangle &dest, float scaleX, float scaleY)
{
        dest.width = 294*scaleX;
        dest.height = 144*scaleY;
        dest.x = GetScreenWidth()/2 - dest.width/2;
        dest.y = GetScreenHeight() - dest.height - 100;
}
void Menu::collision(Rectangle startDest, Rectangle stopDest, bool &started, bool &exited, Sound hit)
{
        if(CheckCollisionPointRec(GetMousePosition(), startDest) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(hit);
            started = true;
        }
        else if(CheckCollisionPointRec(GetMousePosition(), stopDest) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(hit);
            exited = true;
        }
}
void Menu::draw(Texture2D start, Texture2D stop, Rectangle startDest, Rectangle stopDest, Rectangle startSrc, Rectangle stopSrc)
{
        DrawTexturePro(start, startSrc, startDest, {0,0}, 0.0f, WHITE);
        DrawTexturePro(stop, stopSrc, stopDest, {0,0}, 0.0f, WHITE);
}
