#include "Actor.hpp"
#include "Camera.hpp"
#include "Config.hpp"
#include "Model.hpp"
#include "ModelAble.hpp"
#include "MVC.hpp"
#include <stdio.h>
#include "World.hpp"
#include <algorithm>
#include "Button.hpp"

using namespace Game;
using namespace Config::Model;

Model::Model(MVC *mvc)
    : camera(nullptr),
      mvc(mvc),
      timePrior(0),
      world(nullptr)
{
  printf("  Model::Model()\n");
}

void Model::AddActors()
{
}

void Model::DeleteActors()
{
}

void Model::Finalize()
{
  printf("\n  Model::Finalize()\n");

  // Delete the primary camera
  printf("\n  - DELETE CAMERA\n");
  if (camera)
  {
    delete camera;
    camera = nullptr;
  }

  if (world)
  {
    printf("\n  - DELETE WORLD\n");
    delete world;
    world = nullptr;
  }
  if (button)
  {
    delete button;
    button = nullptr;
  }
}

bool Model::Initialize()
{
  printf("  Model::Initialize()\n");
  Actor::SetModel(this);
  // Current version of Model has nothing further to do during initialization.
  return true;
}

void Model::MakeInitialActors()
{
  printf("    Model::MakeInitialActors()\n");

  // Create the world, using the screen's full dimensions as recorded.

  printf("\n  + NEW WORLD\n");
  //TODO: Calculate size of worlds (PERCENTS %)
  world = new World(1.0f, 1.0f);
  // Inform all actors of their world.
  Actor::SetWorld(world);

  // Create the game's primary camera, also using the screen's full dimensions.
  //TODO: Would it still be in pixels or in percentages?
  printf("\n  + NEW CAMERA\n");

  button = new Button("button", 100, 100, 100, 100);
}

void Model::Resize(int width, int height)
{
  printf("  Model::Resize()\n");
  if (hasBeenResized)
  {
    // world->Resize((float)dim.x, (float)dim.y);
    camera->Resize(width, height);
  }
  else
  {
    MakeInitialActors();
    camera->Resize(width, height);
    hasBeenResized = true;
  }
}

void Model::Run()
{
  // Calculate the actual timeChange.
  int timeChange = SDL_GetTicks() - timePrior;
  // Cap the timeChange to LOOP_TIME_MAX specified in config file.
  if (timeChange > LOOP_TIME_MAX)
  {
    timeChange = LOOP_TIME_MAX;
  }
  // Update modelAbles with the timeChange.
  ModelAble::RunAll(timeChange);
  // Detect and handle any collisions between asteroids and lasers.
  // CollideAsteroidsLasers();
  // Add any actors that are to be added to the game.
  AddActors();
  // Delete any actors that are to be terminated.
  DeleteActors();
  // Update timePrior to current time.
  timePrior = SDL_GetTicks();
}