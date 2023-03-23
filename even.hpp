#pragma once
#include "obstacle.hpp"

class Even: public Obstacle{
private:
    int num;
    SDL_Rect src[5];
public:
    Even(SDL_Texture* , SDL_Rect);
    int getX();
    int getY();
    int getH();
    int getW();
    void draw(SDL_Renderer* gRenderer);
    void isCollision();
    void move();
};