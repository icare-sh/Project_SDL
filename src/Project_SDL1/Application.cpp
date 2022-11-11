#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include <math.h>
#include <unistd.h>

#include "Application.hpp"

SDL_Window* Application::create_window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    SDL_Window* window = nullptr;
    if (fullscreen)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
    else
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
    }
    if (window == nullptr)
    {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    return window;
}

SDL_Renderer* Application::create_renderer(SDL_Window* window)
{
    SDL_Renderer* renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    return renderer;
}

void Application::SDL_close(SDL_Window* window, int nb_texture, SDL_Texture** texture, SDL_Renderer* renderer)
{
    for (int i = 0; i < nb_texture; i++)
    {
        SDL_DestroyTexture(texture[i]);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
