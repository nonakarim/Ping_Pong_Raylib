#include <iostream>
#include "raylib.h"

class Paddles{
public:
    virtual void paddle(Rectangle &paddleDest, float scaleX, float scaleY)=0;
};

class Paddle1 : public Paddles{
public:
    Paddle1(Rectangle &paddleDest, float scaleX, float scaleY);
    void paddle(Rectangle &paddleDest, float scaleX, float scaleY) override;
    void draw(Texture2D paddle, Rectangle paddleSrc, Rectangle paddleDest);

    void move(Rectangle &paddleDest, Rectangle ballDest);
};

class Paddle2 : public Paddles{
public:
    Paddle2(Rectangle &Paddle2Dest, float scaleX, float scaleY);
    void paddle(Rectangle &paddleDest, float scaleX, float scaleY) override;

    void draw(Texture2D paddle, Rectangle paddleSrc, Rectangle paddleDest, bool win, Sound winning);

    void move(Rectangle &paddleDest, bool mouse, bool keyboard);
};