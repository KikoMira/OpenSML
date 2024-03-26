#pragma once

#include <cstdint>

#ifdef COMPILER_MSVC
    #ifdef USING_SDL || USING_SDL2
        #include <SDL.h>
    #endif
    #ifdef USING_GLFW
        #include <GLFW/glfw3.h>
    #endif
#endif

#ifdef USING_GCC
    #ifdef USING_SDL
        #include <SDL/SDL.h>
    #endif
    #ifdef USING_SDL2
        #include <SDL2/SDL.h>
    #endif
    #ifdef USING_GLFW
        #include <GLFW/glfw3.h>
    #endif
#endif

// Simple clock to calculate the delta time

struct Clock{
    uint32_t last_tick_time = 0;
    uint32_t delta = 0;

    void tick()
    {
        uint32_t tick_time = 0;
#ifdef USING_SDL
        tick_time = SDL_GetTicks();
#endif
#ifdef USING_SDL2
        tick_time = SDL_GetTicks();
#endif
#ifdef USING_GLFW
        tick_time = glfwGetTime();
#endif
        delta = tick_time - last_tick_time;
        last_tick_time = tick_time;
    }
};

//OpenGL Scene structure

struct Scene{
  virtual void update(float delta) = 0; // Update the scene
  virtual void load_resources() = 0;  // Load scene specific resources
  virtual void play_audio() = 0;       // Handle any scene audio
  virtual void render() = 0;           // Render the scene
  virtual void unload_resources() = 0; // Free resources when scene unloaded
  virtual ~Scene() = default;         // Destructor for cleanup (if needed)
};

// OpenGL Scene Manager structure

struct SceneManager{
    static Scene *currentScene;

    static void set_current_scene(Scene *scene);

    static void run();

    static void load_scene(Scene *scene);
    static void unload_scene();

    static void destroy_scene(Scene *scene);
};
