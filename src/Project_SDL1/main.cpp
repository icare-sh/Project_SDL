#include "SDL.h"
#include <stdio.h>
#include <string>


int main(int argc, char* argv[]) {

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error\n");
    }

    // create a window and a surface
    SDL_Window* window = SDL_CreateWindow("SDL2Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Surface* window_surface = SDL_GetWindowSurface(window);

    // load a png image
    SDL_Surface* image_surface = SDL_LoadBMP("sheep.bmp");
    if (image_surface == NULL) {
        printf("SDL_LoadBMP Error: \n");
        return 1;
    }

    // blit the image to the window
    SDL_BlitSurface(image_surface, NULL, window_surface, NULL);

    // update the window
    SDL_UpdateWindowSurface(window);

    // wait 5 seconds
    SDL_Delay(5000);


    // free the image surface
    SDL_FreeSurface(image_surface);

    // update the window
    SDL_UpdateWindowSurface(window);

  

    // wait 5 seconds
    SDL_Delay(5000);

    // quit SDL
    SDL_Quit();
    
    return 0;
}
