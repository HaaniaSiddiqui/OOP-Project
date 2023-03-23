#pragma once
#include "obstacle.hpp"

class Odd: public Obstacle{
private:
    int num;
    SDL_Rect src[5];
public:
    Odd(SDL_Texture* , SDL_Rect);
    int getX();
    int getY();
    int getH();
    int getW();
    void draw(SDL_Renderer* gRenderer);
    void isCollision();
    void move();
};