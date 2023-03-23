#include "pigeon.hpp"

Pigeon ::Pigeon(SDL_Texture *asst, SDL_Rect move): Obstacle(asst, move){
    //Assigning src appropriately
    src[0] = {6, 0, 155, 101};
    src[1] = {0, 157, 153, 83};
    src[3] = {2, 271, 158, 123};
    collision = false;
}

int Pigeon:: getX(){
    return mover.x;
}

int Pigeon:: getY(){
    return mover.y;
}

int Pigeon:: getW(){
    return mover.h;
}

int Pigeon:: getH(){
    return mover.h;
}

void Pigeon::draw(SDL_Renderer* gRenderer){
    if (x>=3){ // when frame becomes 3 , it again becomes 0
            x=0;
    }
    SDL_RenderCopy(gRenderer, assets, &src[x], &mover);  //texture, animation for flying
    x+=1;
    move();
}

void Pigeon::isCollision(){
    collision=true;
}

void Pigeon::move(){
    mover.x = mover.x - 5;
}
