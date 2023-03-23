#include "SDL.h"
#pragma once
class Objects{
protected:
    // SDL_Renderer* gRenderer;
    SDL_Texture* assets;
    SDL_Rect src;
    SDL_Rect mover;
public:
    Objects(SDL_Texture*, SDL_Rect);
    virtual void draw(SDL_Renderer*) = 0;
    SDL_Rect getMover();
};
//through getters in child classes, we are getting coordinates of mover and set