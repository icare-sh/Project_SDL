#include <iostream>
#include <SDL.h>
#include "rendered_obj.hpp"
#include <stdlib.h>
#include <time.h>

#define SHAPE_SIZE 100


rendered_obj::rendered_obj(const SDL_Renderer *renderer)
{
    renderer = NULL;
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
    return window;
}

SDL_Renderer* create_renderer(SDL_Window* window)
{
    auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    return renderer;
}

SDL_Surface* load_surface(const char* path)
{
    auto surface = SDL_LoadBMP(path);
    if (surface == NULL)
    {
        std::cout << "Surface could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    return surface;
}

SDL_Texture* create_texture(SDL_Surface* surface, SDL_Renderer* renderer)
{
    auto texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        std::cout << "Texture could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}

void SDL_Close(SDL_Window* window)
{
    SDL_DestroyWindow(window);
}

int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, SDL_Surface *surface)
{
    SDL_bool shouldStop = SDL_FALSE;

    SDL_Rect SrcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
    // random position in DestR
    srand (time (NULL));
    SDL_Rect DestR = { (rand()%1920) / 2 - SHAPE_SIZE / 2 , (rand()%1080) / 2 - SHAPE_SIZE / 2 , SHAPE_SIZE, SHAPE_SIZE};

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    else
    {
        window = create_window("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, true);
        renderer = create_renderer(window);

        surface = load_surface("sheep.bmp");
        texture = create_texture(surface, renderer);
        SDL_FreeSurface(surface);
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
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, &SrcR, &DestR);
            SDL_RenderPresent(renderer);
        }
        SDL_DestroyTexture(texture);
        SDL_DestroyRenderer(renderer);
        SDL_Close(window);
        return 0;
    }
}