#include <iostream>
#include "raylib.h"
#include "menu.h"
#include "background.h"
#include "Paddles.h"
#include "Ball.h"
#include "Declarations.h"
#include "Use.h"
#include <exception>

int main()
{
    try
    {
        int SWidth=800;
        int SHeight=600;
        
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        InitWindow(SWidth, SHeight, "Pong");
        InitAudioDevice();

        Declarations decObj;
        decObj.throwExceptions();

        SetWindowIcon(decObj.icon);
        UnloadImage(decObj.icon);

        bool started=false;
        bool exited=false;
        bool mouse = false;
        bool keyboard = false;
        bool win = false;
        bool lose = false;
        bool played = false;
        bool played2 = false;

        Menu menuObj;
        Background BgObj;
        Paddle1 paddle1Obj(decObj.Paddle1DestRec, (float)GetScreenWidth() / 800.0f, (float)GetScreenHeight() / 600.0f);
        Paddle2 paddle2Obj(decObj.Paddle2DestRec, (float)GetScreenWidth() / 800.0f, (float)GetScreenHeight() / 600.0f);
        Ball BallObj(decObj.BallDestRec, (float)GetScreenWidth() / 800.0f, (float)GetScreenHeight() / 600.0f);
        UseKeyboard UseKeyboardObj;
        UseMouse UseMouseObj;

        int score1=0, score2=0;

        PlayMusicStream(decObj.gamePlay);
        while(!WindowShouldClose())
        {
            float scaleX = (float)GetScreenWidth() / 800.0f;
            float scaleY = (float)GetScreenHeight() / 600.0f;
            
            if(!started)
            {
                if(!played)
                {
                    PlaySound(decObj.pickOne);
                    played=true;
                }
                menuObj.start(decObj.startDestRec, scaleX, scaleY);
                menuObj.stop(decObj.stopDestRec, scaleX, scaleY);

                menuObj.collision(decObj.startDestRec, decObj.stopDestRec, started, exited, decObj.hit);
                if(exited == true)
                {
                    return 0;
                }
            }
            else{
                UseKeyboardObj.set(decObj.UseKeyboardDest, scaleX, scaleY);
                UseMouseObj.set(decObj.UseMouseDest, scaleX, scaleY);
                collision(decObj.UseMouseDest, decObj.UseKeyboardDest, mouse, keyboard, decObj.hit);

                if(mouse || keyboard)
                {
                    BgObj.background(decObj.BgDestRec, scaleX, scaleY);
                    
                    paddle1Obj.paddle(decObj.Paddle1DestRec, scaleX, scaleY);
                    paddle2Obj.paddle(decObj.Paddle2DestRec, scaleX, scaleY);
                    paddle1Obj.move(decObj.Paddle1DestRec, decObj.BallDestRec);
                    paddle2Obj.move(decObj.Paddle2DestRec, mouse, keyboard);
                    BallObj.ball(decObj.BallDestRec, scaleX, scaleY);
                    BallObj.collision(decObj.BallDestRec, decObj.Paddle1DestRec, decObj.Paddle2DestRec, score1, score2, decObj.hit, win, lose);
                    BallObj.update(decObj.BallDestRec, scaleX, scaleY);

                }
                else if(((!mouse) && (!keyboard)) && !played2)
                {
                    PlaySound(decObj.pickOne);
                    played2=true;
                }
            }

            BeginDrawing();
            ClearBackground(WHITE);
            
            if(!started)
            {
                //Draw start and stop
                menuObj.draw(decObj.start, decObj.stop, decObj.startDestRec, decObj.stopDestRec, decObj.startRec, decObj.stopRec);
            }
            else
            {
                UseMouseObj.Draw(decObj.UseMouse, decObj.UseMouseSrc, decObj.UseMouseDest, scaleX, scaleY);
                UseKeyboardObj.Draw(decObj.UseKeyboard, decObj.UseKeyboardSrc, decObj.UseKeyboardDest, scaleX, scaleY);


                if(mouse || keyboard)
                {
                    UpdateMusicStream(decObj.gamePlay);
                    BgObj.draw(decObj.Bg, decObj.BgRec, decObj.BgDestRec);
                    paddle1Obj.draw(decObj.Paddle1, decObj.Paddle1Rec, decObj.Paddle1DestRec);
                    paddle2Obj.draw(decObj.Paddle2, decObj.Paddle2Rec, decObj.Paddle2DestRec, win, decObj.win);
                    BallObj.draw(decObj.Ball, decObj.BallRec, decObj.BallDestRec);
                    DrawText(TextFormat("Score: %d", score2), 50, 0, 31*(scaleX*scaleY), WHITE);
                    DrawText(TextFormat("Score: %d", score1), GetScreenWidth() - (250*scaleX), 0, 31*(scaleX*scaleY), WHITE);

                    if(win)
                    {
                        DrawText("YOU WIN!!!", GetScreenWidth()/(2*scaleY), GetScreenHeight()/(2*scaleX), 31*(scaleX*scaleY), GREEN);
                        EndDrawing();
                        WaitTime(3.0);
                        started = false;
                        mouse = false;
                        keyboard = false;
                        win = false;
                        played=false;
                        played2=false;

                        score1 = 0;
                        score2 = 0;

                        decObj.Paddle1DestRec.x = 50;
                        decObj.Paddle1DestRec.y = GetScreenHeight()/2 - decObj.Paddle2DestRec.height/2;

                        decObj.Paddle2DestRec.x = 50;
                        decObj.Paddle2DestRec.y = GetScreenHeight()/2 - decObj.Paddle2DestRec.height/2;

                        decObj.BallDestRec.x = GetScreenWidth() /2 + decObj.BallDestRec.width /2;
                        decObj.BallDestRec.y = GetScreenHeight() - decObj.BallDestRec.height;
                        decObj.BallDestRec.height += 50;
                        decObj.BallDestRec.width += 50;
                    }

                    
                    if(lose)
                    {
                        PlaySound(decObj.lose);
                        DrawText("YOU LOSE!!!", GetScreenWidth()/2, GetScreenHeight()/2, 31, RED);
                        EndDrawing();
                        WaitTime(2.0f);
                        started = false;
                        mouse = false;
                        keyboard = false;
                        lose = false;
                        played=false;
                        played2=false;

                        score1 = 0;
                        score2 = 0;

                        decObj.Paddle1DestRec.x = 50;
                        decObj.Paddle1DestRec.y = GetScreenHeight()/2 - decObj.Paddle2DestRec.height/2;

                        decObj.Paddle2DestRec.x = 50;
                        decObj.Paddle2DestRec.y = GetScreenHeight()/2 - decObj.Paddle2DestRec.height/2;

                        decObj.BallDestRec.x = GetScreenWidth() /2 + decObj.BallDestRec.width /2;
                        decObj.BallDestRec.y = GetScreenHeight() - decObj.BallDestRec.height;
                        decObj.BallDestRec.height += 50;
                        decObj.BallDestRec.width += 50;
                    }
                }
            }
            EndDrawing();
        }

        decObj.destroy();
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    return 0;
}