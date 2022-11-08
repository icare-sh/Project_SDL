#include <random>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

#include "Project_SDL1.hpp"

// Create a NB_SHEEP of sheep
Mouton * create_sheeps()
{
    Mouton * sheeps = new Mouton[NB_SHEEP];
    return sheeps;

}

//Initiate one class Animal
void render_copy(SDL_Renderer *renderer, SDL_Texture *texture, Animal * animals,int size)
{
    for (int i = 0; i < size; i++)
    {
        //Size of the texture
        SDL_Rect SrcR = {0, 0, animals[i].get_shape_size(), animals[i].get_shape_size()};
        //Position of the texture
        SDL_Rect DestR = { animals[i].get_x() , animals[i].get_y()  , animals[i].get_shape_size(), animals[i].get_shape_size()};
        //Copy the texture to the renderer
        SDL_RenderCopy(renderer, texture, &SrcR , &DestR); 
    }
}

//Maj position of one class Animal
void render_copy_maj_pos(SDL_Renderer *renderer, SDL_Texture *texture, Animal * animals,int size)
{
    for (int i = 0; i < size; i++)
    {
        animals[i].maj_position();
        SDL_Rect SrcR = {0, 0, animals[i].get_shape_size(), animals[i].get_shape_size()};
        SDL_Rect DestR = { animals[i].get_x() , animals[i].get_y()  , animals[i].get_shape_size(), animals[i].get_shape_size()};
        SDL_RenderCopy(renderer, texture, &SrcR , &DestR); 
    }
}


//INIT GAME
int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface *surface) 
{
    //reset random
    srand (time (NULL));

    //Condition to quit the game
    SDL_bool shouldStop = SDL_FALSE; // Bool For loop condition;

    //Call display class
    Display display;
    
    
    // ----Create sheep----
    //Load image with path of img
    texture[1] = display.load_image(renderer, texture[1], surface, "media/sheep1.bmp");
    //Create NB_SHEPP of sheeps & init position
    Mouton * sheeps = create_sheeps();
    //Display sheeps on screen
    render_copy(renderer, texture[1], sheeps, NB_SHEEP);

    //load background image
    texture[0] = display.load_image(renderer, texture[0], surface, "media/background.bmp");
    
    //infinte loop of the game
    while (!shouldStop) 
    {
        //Event with mouse
        SDL_Event event;

        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                shouldStop = SDL_TRUE;
            }
        }
        //Display background
        SDL_RenderCopy(renderer, texture[0], NULL, NULL);
        //Display sheeps
        render_copy_maj_pos(renderer, texture[1], sheeps, NB_SHEEP);
        //Update screen
        SDL_RenderPresent(renderer);
        //FPS
        SDL_Delay(10);
    }
    delete[] sheeps;
    return 0;
}



