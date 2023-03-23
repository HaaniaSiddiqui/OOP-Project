#include "obstacle.hpp"


Obstacle :: Obstacle( SDL_Texture* asst, SDL_Rect move){
    this->assets=asst;
    this->mover=move;
}
