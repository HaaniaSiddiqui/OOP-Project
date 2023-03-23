
#include "SDL.h"

#pragma once

class Obstacle{
protected:
    SDL_Texture* assets;
    SDL_Rect src;
    SDL_Rect mover;
    bool collision;
public:
    Obstacle(SDL_Texture*, SDL_Rect);
    virtual void draw(SDL_Renderer*) = 0;
    virtual void isCollision() = 0;
};