#include <iostream>
#include "raylib.h"

class Background{
public:
    void background(Rectangle &BgDest, float scaleX, float scaleY);

    void draw(Texture2D Bg, Rectangle BgSrc, Rectangle BgDest);
};