#include <stdio.h>
#include <string>

#include "SDL.h"
#include "rendered_obj.hpp"

int main(int argc, char* argv[])
{  
    SDL_Window *window = NULL; // Declare a window
    SDL_Renderer *renderer = NULL; // Declare a renderer
    SDL_Texture *texture = NULL; // Declare a texture
    SDL_Surface *surface = NULL; // Declare a surface

    // Initialize SDL, create a window and set the renderer
    init(window, renderer, texture, surface);
    
    SDL_Quit(); // Quit SDL
    
    return 0;
}
