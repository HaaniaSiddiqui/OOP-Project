
#pragma once
#include "LTexture.hpp"
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>


class Score
{
private:
  SDL_Texture* fTexture; 
  SDL_Surface* texture_surface; //sdl surface for score
  TTF_Font *TFont; 
  std::string text;
  SDL_Colour text_color;
  
  
  int x;
  int y;
  int score;

public:
  Score(TTF_Font* );
  ~Score();
  int getScore();
  void setScore(int);
  Score operator+(int); //increases score
  Score operator-(int); // decreases score
  void set_position(int, int);
  void set_Text(std::string); // text to be rendered along with the score
  //void Set_color(Uint8, Uint8, Uint8);
  //void draw(SDL_Renderer *, bool);
  void draw(SDL_Renderer*);
};
