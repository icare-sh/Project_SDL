#include <random>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

#include "Project_SDL1.hpp"

int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, SDL_Surface *surface)
{
    SDL_bool shouldStop = SDL_FALSE; // Bool For loop condition

    // Call the interaction class
    Interaction interaction; 
    interaction = interaction.interact();
    properties * prop;

    // Get the number of sheeps and wolves
    auto nb_sheep = interaction.get_nb_sheep() ;
    auto nb_wolves = interaction.get_nb_wolves();

    srand (time (NULL)); // Initialize random seed

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1; // return 1 if SDL could not initialize
    }
    else
    {
        // Create window
        window = create_window("SDL2 Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, true);
        renderer = create_renderer(window);

        
        // insert background image

        SDL_Surface* image = SDL_LoadBMP("media/background.bmp");
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
        



        // Load image
        texture = load_image(renderer, texture, surface, "media/sheep.bmp");
        
        SDL_RenderClear(renderer);
        prop = render_copy(renderer, texture, nb_sheep);
        SDL_RenderPresent(renderer);

        // Let the window open infinitely
        while (!shouldStop)
        {
            SDL_Event event;
            prop = present_image_and_clear(renderer, texture, prop, nb_sheep); // Present the image and clear the old one
            while (SDL_PollEvent(&event))
            {
                
                
                if (event.type == SDL_QUIT)
                {
                    shouldStop = SDL_TRUE;
                }
            }            
        }

        // Destroy window and renderer and the texture
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
        SDL_DestroyRenderer(renderer);
        SDL_Close(window);
        delete[] prop;

        return 0; // return 0 if SDL could initialize
    }
}
