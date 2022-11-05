#include <random>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

#include "Project_SDL1.hpp"

int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface *surface) 
{
    properties * prop;
    srand (time (NULL));
    SDL_bool shouldStop = SDL_FALSE; // Bool For loop condition;

    //Call display class
    Display display;
    
    // Get the number of sheeps and wolves
    auto nb_sheep = 5;
    auto nb_wolves = 4;

    // Load the background image
    texture[0] = display.load_image(renderer, texture[0], surface, "media/background.bmp");
    SDL_RenderCopy(renderer, texture[0], NULL, NULL);

    // insert sheep image
    texture[1] = display.load_image(renderer, texture[1], surface, "media/sheep1.bmp");
    prop = render_copy(renderer, texture[1], nb_sheep);
    while (!shouldStop)
        {
            SDL_Event event;

            // Reload the background
            texture[0] = display.load_image(renderer, texture[0], surface, "media/background.bmp");
            SDL_RenderCopy(renderer, texture[0], NULL, NULL);
            
            // Move the sheeps
            prop = present_image_and_clear(renderer, texture[1], prop, nb_sheep); // Present the image and clear the old one
            SDL_RenderPresent(renderer);
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    shouldStop = SDL_TRUE;
                }
            }            
        }
    delete[] prop;
    return 0;
}





/*int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, SDL_Surface *surface)
{
    SDL_bool shouldStop = SDL_FALSE; // Bool For loop condition

    // Call the interaction class
    Interaction interaction; 
    interaction = interaction.interact();
    properties * prop;

    // Get the number of sheeps and wolves
    auto nb_sheep = interaction.get_nb_sheep() ;
    auto nb_wolves = interaction.get_nb_wolves();

     // Initialize random seed

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1; // return 1 if SDL could not initialize
    }
    else
    {
        // Create window
        window = create_window("SDL2 Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, false);
        renderer = create_renderer(window);

        
        // insert background image

        SDL_Surface* load_backgroud = SDL_LoadBMP("media/background.bmp");
        SDL_Texture* background = SDL_CreateTextureFromSurface(renderer, load_backgroud);
        SDL_FreeSurface(load_backgroud);
        
        // background loading
        


        // Load image
        texture = load_image(renderer, texture, surface, "media/sheep1.bmp");
        
        SDL_RenderClear(renderer);
        prop = render_copy(renderer, texture, nb_sheep);
        SDL_RenderPresent(renderer);

        // Let the window open infinitely
        while (!shouldStop)
        {
            SDL_Event event;
            SDL_RenderCopy(renderer, background, NULL, NULL);
            
            prop = present_image_and_clear(renderer, texture, prop, nb_sheep); // Present the image and clear the old one
            SDL_RenderPresent(renderer);
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
*/
