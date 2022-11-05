#include <stdio.h>
#include <string>
#include <SDL.h>

#include "Project_SDL1.hpp"

int main(int argc, char* argv[])
{  
    SDL_Window *window = NULL; // Declare a window
    SDL_Renderer *renderer = NULL; // Declare a renderer
    SDL_Texture **texture = NULL; // Declare a texture
    SDL_Surface *surface = NULL; // Declare a surface
    Application app;

    texture = new SDL_Texture*[2];
    texture[0] = NULL; // Declare texture for background
    texture[1] = NULL; // Declare texture for sheep

    int nb_texture = 2; // Number of texture

    // Initialize SDL, create a window and set the renderer
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    else
    {
        //create window
        window = app.create_window("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
        renderer = app.create_renderer(window);
        init(window, renderer, texture, surface);
    }
    
    app.SDL_close(window, nb_texture, texture, renderer);
    
    delete[] texture;
    return 0;
}
