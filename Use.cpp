#include <iostream>
#include "raylib.h"
#include "Use.h"

void UseMouse::set(Rectangle &Dest, float scaleX, int scaleY)
{
        Dest.width = 492*scaleX;
        Dest.height = 138*scaleY;
        Dest.x = GetScreenWidth()/2 - Dest.width/2;
        Dest.y = GetScreenHeight()/4 - Dest.height/4;
}
void UseMouse::Draw(Texture2D texture, Rectangle src, Rectangle &Dest, float scaleX, int scaleY)
{
    DrawTexturePro(texture, src, Dest, {0, 0}, 0.0f, WHITE);
}

void UseKeyboard::set(Rectangle &Dest, float scaleX, int scaleY) 
{
        Dest.width = 492*scaleX;
        Dest.height = 138*scaleY;
        Dest.x = GetScreenWidth()/2 - Dest.width/2;
        Dest.y = GetScreenHeight() - Dest.height - 100;
}
void UseKeyboard::Draw(Texture2D texture, Rectangle src, Rectangle &Dest, float scaleX, int scaleY)
{
    DrawTexturePro(texture, src, Dest, {0, 0}, 0.0f, WHITE);
}


void collision(Rectangle MouseDest, Rectangle KeyboardDest, bool &mouse, bool &keyboard, Sound hit)
{
        if(CheckCollisionPointRec(GetMousePosition(), MouseDest) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(hit);
            mouse = true;
        }
        else if(CheckCollisionPointRec(GetMousePosition(), KeyboardDest) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            PlaySound(hit);
            keyboard = true;
        }
}
