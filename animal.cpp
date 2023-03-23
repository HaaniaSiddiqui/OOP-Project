#include "animal.hpp"

Animal ::Animal(SDL_Texture *asst, SDL_Rect move): Obstacle(asst, move){
    //Assigning src appropriately
    src = {0, 0, 228, 221};
    collision = false;
}

int Animal:: getX(){
    return mover.x;
}

int Animal:: getY(){
    return mover.y;
}

int Animal:: getW(){
    return mover.h;
}

int Animal:: getH(){
    return mover.h;
}

void Animal::draw(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer,assets,&src,&mover);
    move();
}

void Animal::isCollision(){
    collision=true;
}

void Animal::move(){
    mover.x = mover.x - 5;
}
