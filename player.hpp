#include"unit.hpp"
#pragma once
class Player: public Unit{
    bool collision;
public:
    Player(SDL_Texture* tex);
    Player(SDL_Texture* , SDL_Rect);
    void draw(SDL_Renderer*);
    int getX();
    int getY();
    int getH();
    int getW();
    void SetCollision();
    void move(int);
};