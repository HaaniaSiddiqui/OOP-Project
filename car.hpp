#pragma once
#include "obstacle.hpp"

class Car: public Obstacle{
public:
    Car(SDL_Texture* , SDL_Rect);
    int getX();
    int getY();
    int getH();
    int getW();
    void draw(SDL_Renderer* gRenderer);
    void isCollision();
    void move();
};