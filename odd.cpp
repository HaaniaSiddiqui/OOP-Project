#include "odd.hpp"

Odd ::Odd(SDL_Texture *asst, SDL_Rect move): Obstacle(asst, move){
    int x;
    x = rand()%5;
    num = x - 1;
    //Assigning src appropriately
    src[0] = {23, 19, 74, 81};
    src[1] = {189, 19, 74, 81};
    src[2] = {353, 20, 76, 81};
    src[3] = {105, 244, 74, 79};
    src[4] = {272, 244, 73, 80};
    collision = false;
}

int Odd:: getX(){
    return mover.x;
}

int Odd:: getY(){
    return mover.y;
}

int Odd:: getW(){
    return mover.h;
}

int Odd:: getH(){
    return mover.h;
}

void Odd::draw(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer,assets,&src[num],&mover);
    move();
}

void Odd::isCollision(){
    collision=true;
}

void Odd::move(){
    mover.x = mover.x - 5;
}
