#include "Config.hpp"
#include "Controller.hpp"
// #include "KeyAble.hpp"
#include "MouseAble.hpp"
#include "MVC.hpp"
#include <SDL2/SDL.h>
#include <iostream>

using namespace Game;
using namespace Config::Controller;

Controller::Controller(MVC *mvc)
    : dim(mvc->GetDim()),
      mvc(mvc)
{
  printf("\n  Controller::Controller()\n");
  // Current Controller version has nothing further to do during construction.
}

void Controller::Finalize()
{
  printf("  Controller::Finalize()\n");
  // Current version of Controller has nothing to finalize.
}

bool Controller::Initialize()
{
  printf("  Controller::Initialize()\n");
  // Current version of Controller has nothing to initialize.
  return true;
}

void Controller::Resize(int width, int height)
{
  printf("  Controller::Resize()\n");
  // Current version of Controller has nothing to do when screen is resized.
  // mvc->FinishResizingController();
}

void Controller::Run()
{
  // Loop through events that have accumulated since last animation frame.
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      // Game-stopping events are handled by the mvc.
      mvc->Stop();
      break;
    //TODO: mouse -> call other helper functions to make buttons and sliders work.
    case SDL_MOUSEBUTTONDOWN:
      // int x = SDL_MouseMotionEvent().x;
      // int y = SDL_MouseMotionEvent().y;
      std::cout << "Controller reference to screen dim: " << dim.x << ", " << dim.y << std::endl;

      MouseAble::RunAll(&event, dim.x, dim.y);
      // MouseAble::SetCursorPos(x, y);
      break;
    case SDL_MOUSEBUTTONUP:
      break;
    case SDL_MOUSEMOTION:
      break;
    case SDL_MOUSEWHEEL:
      break;
      // Mouse events are passed to mouseAbles (maybe multiple times per cycle).
      // MouseAble::RunAll(&event);
    default:
      // Note: There are other types of events that can be handled, if needed.
      break;
    }
  }

  // Get the present state of the keyboard.
  Uint8 const *keyState = SDL_GetKeyboardState(NULL);
  // Note that the STOP_GAME key is specified in the Config file.
  if (keyState[KEY_STOP_GAME])
  {
    // A game-stopping keyState is handled by the mvc.
    mvc->Stop();
  }
  // else
  // {
  //   // The keyState is passed to keyAbles (just one time per loop).
  //   KeyAble::RunAll(keyState);
  // }
}
