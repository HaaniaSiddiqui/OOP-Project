#include "rock.hpp"

Rock ::Rock(SDL_Texture *asst, SDL_Rect move): Obstacle(asst, move){
    //Assigning src appropriately
    collision = false;
}

int Rock:: getX(){
    return mover.x;
}

int Rock:: getY(){
    return mover.y;
}

int Rock:: getW(){
    return mover.h;
}

int Rock:: getH(){
    return mover.h;
}

void Rock::draw(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer,assets,&src,&mover);
}

void Rock::isCollision(){
    collision=true;
}
