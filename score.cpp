#include<iostream>
#include "Score.hpp"

Score::Score(TTF_Font *font)
{
  fTexture = NULL;
  texture_surface = NULL;
  score = 0;
  TFont = font;
  x=y=10;
  text = "Score: ";
  text_color = {0, 0, 0, 255};
}

Score Score::operator+(int _score)
{
  score += _score;
  return *this;
}
// void Score::Set_color(Uint8 R, Uint8 B, Uint8 G)
// {
//   color = {R, B, G, 255};
// }
Score Score::operator-(int _score)
{
  score -= _score;
  return *this;
}
void Score::draw(SDL_Renderer *gRenderer)
{
  std::stringstream ss;
  ss << text << std::to_string(score);
  //SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), text_color);

  texture_surface = TTF_RenderText_Solid(TFont, ss.str().c_str(), text_color);
  if (texture_surface != NULL)
  {
    fTexture = SDL_CreateTextureFromSurface(gRenderer, texture_surface);
    int t_width = texture_surface->w; // assign the width of the texture
    int t_height = texture_surface->h; // assign the height of the texture
    SDL_Rect dstRect = {x, y,t_width , t_height};
    SDL_RenderCopy(gRenderer, fTexture, NULL, &dstRect);
  }
}


//change
int Score::getScore()
{
  return score;
}
void Score::setScore(int _score) //change
{
  score = _score;
}
void Score::set_position(int nx, int ny)
{
  x = nx;
  y = ny;
}

void Score::set_Text(std::string _text) //change
{
  text = _text;
}
Score::~Score()
{
  SDL_FreeSurface(texture_surface);
  texture_surface = NULL;
  SDL_DestroyTexture(fTexture);
  std::cout << "Score has been destructed"
            << "\n";
}