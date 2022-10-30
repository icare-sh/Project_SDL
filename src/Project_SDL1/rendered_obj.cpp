#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include <math.h>
#include <unistd.h>
#include "rendered_obj.hpp"


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

SDL_Texture* load_image(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Surface* surface, const char* path)
{
    surface = load_surface(path);
    texture = create_texture(surface, renderer);
    SDL_FreeSurface(surface);

    return texture; // return a texture object
}


void SDL_Close(SDL_Window* window)
{
    SDL_DestroyWindow(window);
}


