#ifndef PROJECT_SDL1_HPP
#define PROJECT_SDL1_HPP
#define NB_SHEEP 10
#define NB_WOLF 4


#include "Mouton.hpp"
#include "Wolf.hpp"
#include "Shepherd.hpp"
#include "Shepherd_dog.hpp"

/*
* Init game
* Description: Init game with the given parameters
*/
int game(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface *surface);
Mouton * create_sheeps();
Wolf * create_wolves();

#endif // PROJECT_SDL1_HPP
