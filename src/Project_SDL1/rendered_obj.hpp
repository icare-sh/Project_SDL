#include <SDL.h>
#include <iostream>
#include "Interaction.hpp"


class rendered_obj: public Interaction {
    public:
        rendered_obj() = default;
        ~rendered_obj() = default;
        Interaction interact() const override;

};

SDL_Window* create_window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
SDL_Renderer* create_renderer(SDL_Window* window);
SDL_Surface* load_surface(const char* path);
SDL_Texture* create_texture(SDL_Surface* surface, SDL_Renderer* renderer);
void SDL_Close(SDL_Window* window);
int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, SDL_Surface *surface);
Interaction render_copy(SDL_Renderer* renderer, SDL_Texture* texture, Interaction interaction);