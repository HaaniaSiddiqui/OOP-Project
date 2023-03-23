#include "even.hpp"

Even ::Even(SDL_Texture *asst, SDL_Rect move): Obstacle(asst, move){
    int x;
    x = rand()%5;
    num = x - 1;
    //Assigning src appropriately
    src[0] = {106, 19, 74, 81};
    src[1] = {273, 19, 76, 81};
    src[2] = {22, 243, 73, 81};
    src[3] = {189, 244, 73, 80};
    src[4] = {355, 243, 74, 81};

    collision = false;
}

int Even:: getX(){
    return mover.x;
}

int Even:: getY(){
    return mover.y;
}

int Even:: getW(){
    return mover.h;
}

int Even:: getH(){
    return mover.h;
}

void Even::draw(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer,assets,&src[num],&mover);
}

void Even::isCollision(){
    collision=true;
}

void Even::move(){
    mover.x = mover.x - 5;
}