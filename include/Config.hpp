#include <SDL2/SDL.h> // for Uint32

#pragma once

/* Note: To reduce time-consuming recompilation whenever configuration settings
are modified, declare the config settings in this .hpp file -- but define
their values in a separate Config.cpp file. */

namespace Game::Config
{
  namespace Actor
  {
    namespace Background
    {
      // Location of image file.
      extern char const *IMAGE_FILENAME;

      // Actual pixel height of the source image.
      extern int const IMAGE_HEIGHT;

      // Actual pixel width of the source image.
      extern int const IMAGE_WIDTH;

      // Aspect ratio of image.
      // extern float const ASPECT_RATIO;
    }
  }

  namespace Controller
  {
    // Designates key to immediately stop the game.
    extern Uint8 const KEY_STOP_GAME;
  }

  namespace Model
  {
    // Maximum allowable time change between cycles.
    extern int const LOOP_TIME_MAX;

    // Number of asteroids.
    // extern int const NUM_ASTEROIDS;

    // Strength of gravity pulling player down on jumps
    extern float const GRAVITY;
  }


  namespace View
  {
    // Specifies which SDL subsystems to activate.
    extern Uint32 const INIT_SDL_FLAGS;

    // Specifies details about window when created.
    extern Uint32 const INIT_WINDOW_FLAGS;
  }

}
