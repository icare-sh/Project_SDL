#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include <math.h>
#include <unistd.h>
#include "rendered_obj.hpp"

#define SHAPE_SIZE 80

Interaction Interaction::interact() const
{
    Interaction new_interaction;
    new_interaction.set_nb_sheep(100);
    new_interaction.set_nb_wolves(3);
    return new_interaction; // return a new interaction object
}

SDL_Window* create_window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    Uint32 flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
    }
    auto window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (window == NULL)
    {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    return window; // return a window object
}

SDL_Renderer* create_renderer(SDL_Window* window)
{
    auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    return renderer; // return a renderer object
}

SDL_Surface* load_surface(const char* path)
{
    auto surface = SDL_LoadBMP(path);
    if (surface == NULL)
    {
        std::cout << "Surface could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    return surface; // return a surface object
}

SDL_Texture* create_texture(SDL_Surface* surface, SDL_Renderer* renderer)
{
    auto texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        std::cout << "Texture could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    return texture; // return a texture object 
}

void SDL_Close(SDL_Window* window)
{
    SDL_DestroyWindow(window);
}

properties * render_copy(SDL_Renderer* renderer, SDL_Texture* texture, Interaction interaction)
{
    properties *prop = new properties[interaction.get_nb_sheep()];
    for (int i = 0; i < interaction.get_nb_sheep(); i++)
    {
        SDL_Rect SrcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
        SDL_Rect DestR = { (rand()%1920) / 2 - SHAPE_SIZE / 2 , (rand()%1080) / 2 - SHAPE_SIZE / 2 , SHAPE_SIZE, SHAPE_SIZE};
        prop[i].x = DestR.x;
        prop[i].y = DestR.y;
        prop[i].speed = 2;
        prop[i].direction_x = rand() % 10;
        prop[i].direction_y = rand() % 10;
        SDL_RenderCopy(renderer, texture, &SrcR, &DestR);

    }
    
    return prop; // return a new interaction object
}

properties * render_copy_maj_pos(SDL_Renderer* renderer, SDL_Texture* texture, properties *prop, Interaction interaction)
{
    float temp_taux = 0.1;
    for (int i = 0; i < interaction.get_nb_sheep(); i++)
    {
        SDL_Rect SrcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
        temp_taux = sqrt(pow(prop[i].direction_x, 2) + pow(prop[i].direction_y, 2));
        
        SDL_Rect DestR = { int(prop[i].x + prop[i].speed * prop[i].direction_x / temp_taux), int(prop[i].y + prop[i].speed * prop[i].direction_y / temp_taux) , SHAPE_SIZE, SHAPE_SIZE};
        prop[i].x = DestR.x;
        prop[i].y = DestR.y;
        printf("x = %d, y = %d, speed = %f, direction_x = %f, direction_y = %f", prop[i].x, prop[i].y, prop[i].speed, prop[i].direction_x, prop[i].direction_y);
        SDL_RenderCopy(renderer, texture, &SrcR, &DestR);
    }
    
    return prop; // return a new interaction object
}

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
        window = create_window("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, true);
        renderer = create_renderer(window);

        // Load image
        surface = load_surface("media/sheep.bmp");
        texture = create_texture(surface, renderer);
        SDL_FreeSurface(surface);
        SDL_RenderClear(renderer);
        prop = render_copy(renderer, texture, interaction);
        SDL_RenderPresent(renderer);

        // Let the window open infinitely
        while (!shouldStop)
        {
            SDL_Event event;
            printf("maj des données\n");
            prop = render_copy_maj_pos(renderer, texture, prop, interaction);
            SDL_RenderPresent(renderer);
            SDL_RenderClear(renderer);
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
        SDL_DestroyRenderer(renderer);
        SDL_Close(window);
        delete[] prop;

        return 0; // return 0 if SDL could initialize
    }
}
