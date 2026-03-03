#include <iostream>
#include "raylib.h"

class Menu{
public:
    void start(Rectangle &dest, float scaleX, float scaleY);
    void stop(Rectangle &dest, float scaleX, float scaleY);
    void collision(Rectangle startDest, Rectangle stopDest, bool &started, bool &exited, Sound hit);
    void draw(Texture2D start, Texture2D stop, Rectangle startDest, Rectangle stopDest, Rectangle startSrc, Rectangle stopSrc);
};