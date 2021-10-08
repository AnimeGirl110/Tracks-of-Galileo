#include "Config.hpp"

namespace Game::Config
{
    namespace Actor
    {

    }

    namespace Controller
    {
        Uint8 const
            KEY_STOP_GAME =
                SDL_SCANCODE_ESCAPE;
    }

    namespace Model
    {
        int const
            LOOP_TIME_MAX =
                50;
        // Specified in milliseconds.

        // int const
        //     NUM_ASTEROIDS =
        //         10;
        float const
            GRAVITY =
                0.0001;
        //TODO: Adjust later
    }

    namespace View
    {
        /* INIT_SDL_FLAGS options (which can be joined by | operator) are:
        SDL_INIT_TIMER:          timer subsystem
        SDL_INIT_AUDIO:          audio subsystem
        SDL_INIT_VIDEO:          video subsystem; automatically initializes the
                                 events subsystem
        SDL_INIT_JOYSTICK:       joystick subsystem; automatically initializes
                                 the events subsystem
        SDL_INIT_HAPTIC:         haptic (force feedback) subsystem
        SDL_INIT_GAMECONTROLLER: controller subsystem; automatically initializes
                                 the joystick subsystem
        SDL_INIT_EVENTS:         events subsystem
        SDL_INIT_EVERYTHING:     all of the above subsystems
        SDL_INIT_NOPARACHUTE:    compatibility; this flag is ignored
    */
        Uint32 const
            INIT_SDL_FLAGS =
                SDL_INIT_VIDEO | SDL_INIT_AUDIO;

        /* INIT_WINDOW_FLAGS options (which can be joined by | operator) are :
        SDL_WINDOW_FULLSCREEN:         fullscreen window
        SDL_WINDOW_FULLSCREEN_DESKTOP: fullscreen window at desktop resolution
        SDL_WINDOW_OPENGL:             window usable with an OpenGL context
        SDL_WINDOW_VULKAN:             window usable with a Vulkan instance
        SDL_WINDOW_METAL:              window usable with a Metal instance
        SDL_WINDOW_HIDDEN:             window is not visible
        SDL_WINDOW_BORDERLESS:         no window decoration
        SDL_WINDOW_RESIZABLE:          window can be resized
        SDL_WINDOW_MINIMIZED:          window is minimized
        SDL_WINDOW_MAXIMIZED:          window is maximized
        SDL_WINDOW_INPUT_GRABBED:      window has grabbed input focus
        SDL_WINDOW_ALLOW_HIGHDPI:      window should be created in high-DPI mode
                                       if supported (>= SDL 2.0.1)
    */
        Uint32 const
            INIT_WINDOW_FLAGS =
                0;
        // 0 means no window flags are being set.
    }
}