#include <random>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

#include "Project_SDL1.hpp"

int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface *surface) 
{
    properties *prop = NULL;
    srand (time (NULL));
    SDL_bool shouldStop = SDL_FALSE; // Bool For loop condition;

    //Call display class
    Display display;
    
    // Get the number of sheeps and wolves
    auto nb_sheep = 5;
    auto nb_wolves = 4;

    // insert sheep image
    texture[1] = display.load_image(renderer, texture[1], surface, "media/sheep1.bmp");
    
    prop = render_copy(renderer, texture[1], nb_sheep);
    
    //load background imahe and sheep infini loop
    texture[0] = display.load_image(renderer, texture[0], surface, "media/background.bmp");
    
    while (!shouldStop) 
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                shouldStop = SDL_TRUE;
            }
        }
        SDL_RenderCopy(renderer, texture[0], NULL, NULL);
        prop = render_copy_maj_pos(renderer, texture[1], prop, nb_sheep);
        SDL_RenderPresent(renderer);
    }
    delete[] prop;
    return 0;
}


