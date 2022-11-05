#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include <math.h>
#include <unistd.h>

#include "Display.hpp"


SDL_Surface* Display::load_surface(const char* path)
{
    SDL_Surface* surface = nullptr;
    surface = SDL_LoadBMP(path);
    if (surface == nullptr)
    {
        std::cout << "Surface could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    return surface;
}

SDL_Texture* Display::create_texture(SDL_Surface* surface, SDL_Renderer* renderer)
{
    auto texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        std::cout << "Texture could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    return texture; // return a texture object 
}

SDL_Texture* Display::load_image(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Surface* surface, const char* path)
{
    surface = load_surface(path);
    texture = create_texture(surface, renderer);
    
    return texture;
}
