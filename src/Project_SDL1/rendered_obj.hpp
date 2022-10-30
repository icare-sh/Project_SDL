#include <SDL.h>
#include <iostream>
#include "Interaction.hpp"


class rendered_obj: public Interaction {
    public:
        rendered_obj() = default;
        ~rendered_obj() = default;
        Interaction interact() const override;

};

/*
* Create a window
* Description: Create a window with the given parameters
*/
SDL_Window* create_window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

/*
* Create a renderer
* Description: Create a renderer with the given parameters
*/
SDL_Renderer* create_renderer(SDL_Window* window);

/*
* Load a surface
* Description: Load a surface with the given parameters
*/
SDL_Surface* load_surface(const char* path);

/*
* Create a texture
* Description: Create a texture with the given parameters
*/
SDL_Texture* create_texture(SDL_Surface* surface, SDL_Renderer* renderer);

/*
* Close the window
* Description: Close the window with the given parameters
*/
void SDL_Close(SDL_Window* window);

/*
* Initialize SDL
* Description: Initialize SDL with the given parameters and begin the game
*/
int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, SDL_Surface *surface);

/*
* Create X Sheeps from Interaction class and render them
* Description: Create X Sheeps from Interaction class and render them
*/
Interaction render_copy(SDL_Renderer* renderer, SDL_Texture* texture, Interaction interaction);