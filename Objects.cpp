#include<iostream>
#include "Objects.hpp"
Objects ::Objects( SDL_Texture* assets, SDL_Rect Mover){
    this->assets=assets; //assigning texture which have to be rendered
    this->mover=Mover;   //assigning position at which assets have to be renderd.
    
}