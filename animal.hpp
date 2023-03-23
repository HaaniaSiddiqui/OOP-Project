#pragma once
#include "obstacle.hpp"

class Animal: public Obstacle{
public:
    Animal(SDL_Texture* , SDL_Rect);
    int getX();
    int getY();
    int getH();
    int getW();
    void draw(SDL_Renderer* gRenderer);
    void isCollision();
    void move();
};