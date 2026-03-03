#include "background.h"


void Background::background(Rectangle &BgDest, float scaleX, float scaleY){
    BgDest.x = 0;
    BgDest.y = 0;
    BgDest.width = 800 * scaleX;
    BgDest.height = 600 * scaleY;
}

void Background::draw(Texture2D Bg, Rectangle BgSrc, Rectangle BgDest)
{
    DrawTexturePro(Bg, BgSrc, BgDest, {0, 0}, 0.0f, WHITE);
}
