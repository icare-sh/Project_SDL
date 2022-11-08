#ifndef PROJECT_SDL1_HPP
#define PROJECT_SDL1_HPP
#define NB_SHEEP 10

#include "Mouton.hpp"
class Project_SDL1
{
    public:
        Project_SDL1() = default;
        ~Project_SDL1() = default;
};

/*
* Init game
* Description: Init game with the given parameters
*/
int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface *surface);

Mouton * create_sheeps();
#endif // PROJECT_SDL1_HPP
