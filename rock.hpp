#pragma once
#include "obstacle.hpp"

class Rock: public Obstacle{
public:
    Rock(SDL_Texture* , SDL_Rect);
    int getX();
    int getY();
    int getH();
    int getW();
    void draw(SDL_Renderer* gRenderer);
    void isCollision();
};