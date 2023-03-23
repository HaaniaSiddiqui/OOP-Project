#pragma once
#include "obstacle.hpp"

class Pigeon: public Obstacle{
private:
    int num;
    SDL_Rect src[3];
    int x;
public:
    Pigeon(SDL_Texture* , SDL_Rect);
    int getX();
    int getY();
    int getH();
    int getW();
    void draw(SDL_Renderer* gRenderer);
    void isCollision();
    void move();
};