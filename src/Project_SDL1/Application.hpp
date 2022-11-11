#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SDL.h>
#include <iostream>
#include <vector>

#include "Interaction.hpp"

class Application : public Interaction {
    public:
        Application() = default;
        ~Application() = default;
        
        /*
        * @brief Create a window
        * Description: Create a window with the given parameters
        * return: a window
        */
        SDL_Window* create_window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        /*
        * @brief Create a renderer
        * Description: Create a renderer with the given parameters
        * return: a renderer
        */
        SDL_Renderer* create_renderer(SDL_Window* window);

        /*
        * @brief Close SDL
        * Description: Close SDL with the given parameters
        */
        void SDL_close(SDL_Window* window, int nb_texture, SDL_Texture** texture, SDL_Renderer* renderer);

    private:
        char *title;
        int xpos;
        int ypos;
        int width;
        int height;
        bool fullscreen;
        SDL_Window* window;

};

#endif // APPLICATION_HPP
