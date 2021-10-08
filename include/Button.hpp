#pragma once
#include <string>
#include "ViewAble.hpp"
#include "Actor.hpp"
#include "MouseAble.hpp"

namespace Game
{
  class Button : public Actor, public ViewAble, public MouseAble
  {
  public:
    Button(std::string v, float posX, float posY, float dimX, float dimY);

    void RunMouseAble() override;

  private:
    std::string value;
  };
}