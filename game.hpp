#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
// #include <SDL.h>
// #include <SDL_image.h>
// #include <stdio.h>
// #include <iostream>
// #include <string>
// #include <SDL_ttf.h>
// #include <stdlib.h>
// #include <time.h>
// #include <list>
// #include <sstream>

#include "car.hpp"
#include "even.hpp"
#include "obstacle.hpp"
#include "odd.hpp"
#include "rock.hpp"
#include "bar.hpp"
#include "animal.hpp"
#include "pigeon.hpp"
#include "player.hpp"
#include "score.hpp"
#include "LTexture.hpp"
using namespace std;

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* frame[3];
    //global reference to png image sheets
    SDL_Texture* carTex=NULL;
    SDL_Texture* playerI=NULL;
    SDL_Texture* barTex=NULL;
    SDL_Texture* numberTex=NULL;
    SDL_Texture* animalTex=NULL;
    SDL_Texture* pigeonTex=NULL;
    SDL_Texture* rockTex=NULL;
    //Globally used font
    TTF_Font *tFont = NULL;
    //Rendered texture
    LTexture gTextTexture;
    int level;
    int incoming;
    int nums;

    //You may use C++ linked lists, or you can create your own.

    list<Player*> players;
    list<Odd*> ods;
    list<Even*> eves;
    //list<Bar*> bars;
    list<Animal*> animas;
    list<Car*> cars;
    list<Pigeon*> pigu;
    list<Rock*> rocks;


public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    
    void run();
       
    
    // void updateEggs();
    // void updatePigeons();
    void drawAllObjects();
    void UpdateScore();
    
    
    
};