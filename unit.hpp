#include "SDL.h"
#pragma once
enum direction
{
    R,
    L,
    U,
    D
};
class Unit{
protected:
    // SDL_Renderer* gRenderer;
    SDL_Texture* assets;
    SDL_Rect src;
    SDL_Rect mover;
    int moveX=15;
    int moveY=30;
    int x;
    int y;
public:
    Unit(SDL_Texture*, SDL_Rect);
    virtual void draw(SDL_Renderer*) = 0;
    SDL_Rect getMover();
    virtual void move(int);
};
//through getters in child classes, we are getting coordinates of mover and set