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

Wolf * create_wolves()
{
    Wolf * wolves = new Wolf[NB_WOLF];
    return wolves;
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
void render_copy_maj_pos(SDL_Renderer *renderer, SDL_Texture *texture, Animal * animals,Animal * other, int size, int size_other)
{
    //delete the sheep if alive == false

    
    for (int i = 0; i < size; i++)
    {
        if(animals[i].get_alive() == true)
        {
        animals[i].maj_position(animals,other,size,size_other);
        SDL_Rect SrcR = {0, 0, animals[i].get_shape_size(), animals[i].get_shape_size()};
        SDL_Rect DestR = { animals[i].get_x() , animals[i].get_y()  , animals[i].get_shape_size(), animals[i].get_shape_size()};
        SDL_RenderCopy(renderer, texture, &SrcR , &DestR); 
        }
        else
        {
            animals[i].~Animal();
        }
    }

}

void render_copy_maj_pos_mouton(SDL_Renderer *renderer, SDL_Texture *texture, Animal * sheeps,Animal * wolfs, int size_sheeps, int size_wolfs)
{
    //delete the sheep if alive == false

    
    for (int i = 0; i < size_sheeps; i++)
    {
        if(sheeps[i].get_alive() == true)
        {
        sheeps[i].maj_position(wolfs,sheeps,size_wolfs,size_sheeps);
        SDL_Rect SrcR = {0, 0, sheeps[i].get_shape_size(), sheeps[i].get_shape_size()};
        SDL_Rect DestR = { sheeps[i].get_x() , sheeps[i].get_y()  , sheeps[i].get_shape_size(), sheeps[i].get_shape_size()};
        SDL_RenderCopy(renderer, texture, &SrcR , &DestR); 
        }
        else
        {
            sheeps[i].~Animal();
        }
    }

}


void render_copy_maj_pos_wolf(SDL_Renderer *renderer, SDL_Texture *texture, Animal * sheeps,Animal * dog, Animal *wolf, int size_sheeps, int size_dog, int size_wolf)
{
    for (int i = 0; i < size_wolf; i++)
    {
        wolf[i].maj_position(sheeps,dog,size_sheeps,size_dog);
        SDL_Rect SrcR = {0, 0, wolf[i].get_shape_size(), wolf[i].get_shape_size()};
        SDL_Rect DestR = { wolf[i].get_x() , wolf[i].get_y()  , wolf[i].get_shape_size(), wolf[i].get_shape_size()};
        SDL_RenderCopy(renderer, texture, &SrcR , &DestR); 
    }
}


//INIT GAME
int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface *surface) 
{
    //other definition
    int size_other = 10;
    Mouton * other = new Mouton[size_other];
    //reset random
    srand (time (NULL));

    //Condition to quit the game
    SDL_bool shouldStop = SDL_FALSE; // Bool For loop condition;

    //Call display class
    Display display;
    
    
    // ----Create sheep----
    //Load image with path of img
    texture[1] = display.load_image(renderer, texture[1], surface, "media/sheep1.bmp");

    //Load wolf image
    texture[2] = display.load_image(renderer, texture[2], surface, "media/wolf1.bmp");
    //Create NB_SHEPP of sheeps & init position
    Mouton * sheeps = create_sheeps();

    //Create NB_WOLF of wolves & init position
    Wolf * wolves = create_wolves();

    //Display sheeps on screen
    render_copy(renderer, texture[1], sheeps, NB_SHEEP);

    //Display wolves on screen
    render_copy(renderer, texture[2], wolves, NB_WOLF);


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
        render_copy_maj_pos_mouton(renderer, texture[1], sheeps, wolves, NB_SHEEP, NB_WOLF);
   
        //Display wolves
        render_copy_maj_pos_wolf(renderer, texture[2], sheeps, other, wolves, NB_SHEEP, size_other, NB_WOLF);
     
        //Update screen
        SDL_RenderPresent(renderer);
                //FPS
        SDL_Delay(10);
    }
    delete[] sheeps;
    delete[] wolves;
    delete[] other;

    return 0;
}
