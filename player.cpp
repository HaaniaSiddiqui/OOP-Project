#include <iostream>
#include "player.hpp"
using namespace std;
Player ::Player(SDL_Texture *assets, SDL_Rect Mover) : Unit(assets, Mover){
    collision=false; //collision is false when nest is drawn
    
    src = {5,12,129,150}; 
}
void Player:: draw(SDL_Renderer* gRenderer){
    
    SDL_RenderCopy(gRenderer,assets,&src,&mover );
    // if (collision==false  && mover.x>10 && mover.x<798 ){ //nest moves randomly left and right until it collides with an egg then it stops
    //     int y;
    //     y=rand()%100; //a random number
    //     if (y%2==0){ //if even move right
    //         mover.x+=10;
    //     }
    //     else{ //if odd move left
    //         mover.x-=10;
    //     }
        
    // }
    // if (mover.x<=10){
    //     mover.x+=10;
    // }
    
    

}
int Player:: getX(){
    return mover.x;

}
int Player:: getY(){
    return mover.y;
}
int Player:: getW(){
    return mover.w;

}
int Player:: getH(){
    return mover.h;
}
void Player::SetCollision(){
    collision=true;
}
void Player::move(int key)
{

    cout << "HERE";
    if (key== L)
    {
        mover.x -= moveX;
        // if (x <= 50)
        // {
        //     x = 50;
        // }
    }

    if (key== R)
    {
        cout << "RIGHT";
        mover.x+=moveX;
        // if (x > 1024 - 147)
        // {
        //     x = 1024 - 147;
        // }
    }
    if (key== U)
    {
        mover.y -= moveY;
         
        // if (x > 1024 - 147)
        // {
        //     x = 1024 - 147;
        // }
    }
    if (key== D)
    {
        mover.y += moveY;
        // if (x > 1024 - 147)
        // {
        //     x = 1024 - 147;
        // }
    }

}
// bool Player::check_collision(Unit *sprite)
// {
//     if ((this->GetX() >= sprite->GetX() && this->GetX() <= (sprite->GetX() + sprite->GetWidth())) ||
//         ((this->GetX() + this->GetWidth()) >= sprite->GetX() && (this->GetX() + this->GetWidth()) <= (sprite->GetX() + sprite->GetWidth())))
//     {
//         //Now we look at the y axis:
//         if ((this->GetY() >= sprite->GetY() && this->GetY() <= (sprite->GetY() + sprite->GetHeight())) ||
//             ((this->GetY() + this->GetHeight()) >= sprite->GetY() && (this->GetY() + this->GetHeight()) <= (sprite->GetY() + sprite->GetHeight())))
//         {
//             //The sprites appear to overlap.
//             return true;
//         }
//     }
//     return false;
// }