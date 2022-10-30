#include <SDL.h>
#include <iostream>


// class rendered_obj herite de la classe interaction
class rendered_obj
{
    public:
        rendered_obj(const SDL_Renderer *renderer);
        ~rendered_obj() = default;
        // create method for sdl2

};

SDL_Window* create_window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
SDL_Renderer* create_renderer(SDL_Window* window);
SDL_Surface* load_surface(const char* path);
SDL_Texture* create_texture(SDL_Surface* surface, SDL_Renderer* renderer);
void SDL_Close(SDL_Window* window);
int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, SDL_Surface *surface);
