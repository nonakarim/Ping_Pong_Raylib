#include <iostream>
#include "raylib.h"

class Use{
public:
    virtual void set(Rectangle &Dest, float scaleX, int scaleY) = 0;
    virtual void Draw(Texture2D texture, Rectangle src, Rectangle &Dest, float scaleX, int scaleY) = 0;
};

class UseMouse : public Use{
public:
    void set(Rectangle &Dest, float scaleX, int scaleY) override;
    void Draw(Texture2D texture, Rectangle src, Rectangle &Dest, float scaleX, int scaleY) override;
};

class UseKeyboard : public Use{
public:
    void set(Rectangle &Dest, float scaleX, int scaleY) override;
    void Draw(Texture2D texture, Rectangle src, Rectangle &Dest, float scaleX, int scaleY) override;
};

void collision(Rectangle MouseDest, Rectangle KeyboardDest, bool &mouse, bool &keyboard, Sound hit);