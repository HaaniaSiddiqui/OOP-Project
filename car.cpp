#include "car.hpp"

Car ::Car(SDL_Texture *asst, SDL_Rect move): Obstacle(asst, move){
    //Assigning src appropriately
    src = {0, 0, 512, 512};
    collision = false;
}

int Car:: getX(){
    return mover.x;
}

int Car:: getY(){
    return mover.y;
}

int Car:: getW(){
    return mover.h;
}

int Car:: getH(){
    return mover.h;
}

void Car::draw(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer,assets,&src,&mover);
    move();
}

void Car::isCollision(){
    collision=true;
}

void Car::move(){
    mover.x = mover.x - 5;
}
