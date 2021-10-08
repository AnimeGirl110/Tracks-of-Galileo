#include <algorithm>
#include <stdio.h>
#include "MouseAble.hpp"
#include <iostream>

//OK

using namespace Game;

// Static variables must be initialized in cpp code outside of hpp declaration.
SDL_Event *MouseAble::event = nullptr;
std::vector<MouseAble *> MouseAble::mouseAbles;
// Vec2f pos = Vec2f{0, 0};
Vec2i screenDim = Vec2i{0, 0};

void MouseAble::RunAll(SDL_Event *event, int x, int y)
{
  // std::cout << "MouseAble::RunAll: " << dim->x << ", " << dim->y << std::endl;
  MouseAble::screenDim.x = x;
  MouseAble::screenDim.y = y;
  // Update the mouse event, shared by all mouseAbles.
  MouseAble::event = event;

  // Inform all mouseAbles of the update.
  for (auto mouseAble : mouseAbles)
  {
    mouseAble->RunMouseAble();
  }
}

MouseAble::MouseAble()
{
  printf("    MouseAble::MouseAble()\n");
  // Add the new mouseAble to the end of the static collection of mouseAbles.
  mouseAbles.emplace_back(this);
}

// Deletion of mouseAble triggers this destructor, so don't do "delete" op here.
MouseAble::~MouseAble()
{
  printf("    MouseAble::~MouseAble()\n");
  auto it = std::find(mouseAbles.begin(), mouseAbles.end(), this);
  if (it != mouseAbles.end())
  {
    // This quick deletion trick works so long as the vector isn't "ordered."
    std::iter_swap(it, mouseAbles.end() - 1);
    mouseAbles.pop_back();
  }
}
