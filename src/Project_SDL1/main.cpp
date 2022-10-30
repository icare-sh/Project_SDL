#include "SDL.h"
#include "rendered_obj.hpp"

#include <stdio.h>
#include <string>


int main(int argc, char* argv[]) {
    // create window
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    SDL_Surface *surface = NULL;

    init(window, renderer, texture, surface);
    
    SDL_Quit();
    
    return 0;
}
