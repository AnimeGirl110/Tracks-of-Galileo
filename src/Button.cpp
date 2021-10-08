#include "Button.hpp"
#include <iostream>

using namespace Game;

//pos in %
Button::Button(std::string v, float posX, float posY, float dimX, float dimY)
    : Actor(posX, posY, 0, dimX, dimY),
      ViewAble(this->Actor::pos, this->Actor::ori, this->Actor::dim, NULL),
      MouseAble(),
      value(v)
{
}

void Button::RunMouseAble()
{
  if (event->type == SDL_MOUSEBUTTONDOWN)
  {
    std::cout << "Button::RunMouseAble: " << screenDim.x << ", " << screenDim.y << std::endl;
    int x, y;
    SDL_GetMouseState(&x, &y);
    std::cout << "Mouse down at " << x << ", " << y << std::endl;
    // float fx = (float)x / screenDim->x;
    // float fy = (float)y /  screenDim->y;
    // std::cout << "Mouse down at FLOATS: " << fx << ", " << fy << std::endl;
  }
}