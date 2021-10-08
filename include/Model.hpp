#pragma once
#include <SDL2/SDL.h>
// #include "Vec2i.hpp"
#include <vector>

namespace Game
{
  // Class for managing game state (data) in the Model-View-Controller paradigm.
  class Model
  {
  public:
    // Constructs the application's model.
    Model(class MVC *mvc);

    void DeleteActors();
    void Finalize();
    // Called by parent MVC object at start to initialize resources, if any.
    bool Initialize();
    // Called when the screen has been resized.
    void Resize(int width, int height);
    // Called each application cycle to run any ModelAble actors.
    void Run();

  private:
    // Perform actual emplacement of any actors marked for addition to game.
    void AddActors();
    void MakeInitialActors();

    class Camera *camera;
    bool hasBeenResized;
    class MVC *mvc;
    Uint32 timePrior;
    // Pointer to game's world.
    class World *world;
    class Button *button;
  };
}
