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

// Create a NB_WOLF of wolf
Wolf * create_wolves()
{
    Wolf * wolves = new Wolf[NB_WOLF];
    return wolves;
}

// Create a NB_SHEPHERD_DOG of shepherd dog
Shepherd_dog * create_shepherd_dog()
{
    Shepherd_dog * shepherd_dogs = new Shepherd_dog[NB_SHEPHERD_DOG];
    return shepherd_dogs;
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
        animals[i].maj_position(animals,other,size,size_other,NULL);
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

//Maj position of sheeps
void render_copy_maj_pos_mouton(SDL_Renderer *renderer, SDL_Texture *texture, Animal * sheeps,Animal * wolfs, int size_sheeps, int size_wolfs)
{
    //delete the sheep if alive == false

    
    for (int i = 0; i < size_sheeps; i++)
    {
        if(sheeps[i].get_alive() == true)
        {
        maj_timer(&sheeps[i],sheeps[i].get_time());
        sheeps[i].maj_position(wolfs,sheeps,size_wolfs,size_sheeps,NULL);
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

//Maj position of wolfs
void render_copy_maj_pos_wolf(SDL_Renderer *renderer, SDL_Texture *texture, Animal * sheeps,Animal * dog, Animal *wolf, int size_sheeps, int size_dog, int size_wolf,Shepherd * shepherd)
{
    //delete the sheep if alive == false

    
    for (int i = 0; i < size_wolf; i++)
    {
        if(wolf[i].get_alive() == true)
        {
        maj_timer(&wolf[i],wolf[i].get_time());
        wolf[i].maj_position(sheeps,dog,size_sheeps,size_dog,shepherd);
        SDL_Rect SrcR = {0, 0, wolf[i].get_shape_size(), wolf[i].get_shape_size()};
        SDL_Rect DestR = { wolf[i].get_x() , wolf[i].get_y()  , wolf[i].get_shape_size(), wolf[i].get_shape_size()};
        SDL_RenderCopy(renderer, texture, &SrcR , &DestR); 
        }
        else
        {
            wolf[i].~Animal();
        }
    }

}


//Initiate one class Shepherd
void render_copy_shepherd(SDL_Renderer *renderer, SDL_Texture *texture, Shepherd shepherd)
{
    SDL_Rect SrcR = {0, 0, shepherd.get_shape_size(), shepherd.get_shape_size()};
    SDL_Rect DestR = { shepherd.get_x() , shepherd.get_y()  , shepherd.get_shape_size(), shepherd.get_shape_size()};
    SDL_RenderCopy(renderer, texture, &SrcR , &DestR); 
}

//Maj position of shepherd dog
void render_copy_maj_pos_shepherd_dog(SDL_Renderer *renderer, SDL_Texture *texture, Animal  * dog, int x, int y, Animal *other)
{
    for (int i = 0; i < NB_SHEPHERD_DOG; i++)
    {
        dog[i].maj_position(dog,other, x,y,NULL);
        SDL_Rect SrcR = {0, 0, dog[i].get_shape_size(), dog[i].get_shape_size()};
        SDL_Rect DestR = { dog[i].get_x() , dog[i].get_y()  , dog[i].get_shape_size(), dog[i].get_shape_size()};
        SDL_RenderCopy(renderer, texture, &SrcR , &DestR); 
    }
}

void get_shepherd_direction(SDL_Event event, Shepherd *shepherd)

{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:
                shepherd->move_up();
                break;
            case SDLK_DOWN:
                shepherd->move_down();
                break;
            case SDLK_LEFT:
                shepherd->move_left();
                break;
            case SDLK_RIGHT:
                shepherd->move_right();
                break;
        }
    }
}

int increase_nb_wolves(Interaction *interaction, int timer)
{   
    if (interaction->get_nb_wolves() < NB_WOLF && timer == 700)
    {
        interaction->set_nb_wolves(interaction->get_nb_wolves() + 1);
        timer = 0;
        return timer;
    }
    return timer + 1;
}

//INIT GAME
int init(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface *surface) 
{
    //other definition
    int size_other = NB_SHEEP;
    Mouton * other = new Mouton[size_other];
    Interaction interaction;

    srand (time (NULL)); //reset random

    SDL_bool shouldStop = SDL_FALSE; // Bool For loop condition;

    Display display; //Call display class

    texture[0] = display.load_image(renderer, texture[0], surface, "media/background.bmp"); //load background image
    texture[1] = display.load_image(renderer, texture[1], surface, "media/sheep1.bmp"); //Load image with path of img
    texture[2] = display.load_image(renderer, texture[2], surface, "media/wolf1.bmp"); //Load wolf image
    texture[3] = display.load_image(renderer, texture[3], surface, "media/Berger.bmp"); //Load shepherd image
    texture[4] = display.load_image(renderer, texture[4], surface, "media/dog.bmp"); //Load shepherd dog image

    Mouton * sheeps = create_sheeps(); //Create NB_SHEPP of sheeps & init position
    Wolf * wolves = create_wolves(); //Create NB_WOLF of wolves & init position
    Shepherd_dog  * shepherd_dogs = create_shepherd_dog(); //Call shepherd_dog class
    auto shepherd = Shepherd(); //Call shepherd class

    render_copy(renderer, texture[1], sheeps, interaction.get_nb_sheep()); //Display sheeps on screen
    render_copy(renderer, texture[2], wolves, interaction.get_nb_wolves()); //Display wolves on screen
    render_copy(renderer, texture[4], shepherd_dogs, NB_SHEPHERD_DOG); //Display shepherd dog on screen

    //timer of the game
    int timer = 0;

    while (!shouldStop) 
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
             switch (event.type) 
             {
                case SDL_QUIT:
                    shouldStop = SDL_TRUE;
                    break;
                case SDL_KEYDOWN:
                    get_shepherd_direction(event, &shepherd);
                    break;
                default:
                    break;
             }
        }
        
        SDL_RenderCopy(renderer, texture[0], NULL, NULL); //Display background
        render_copy_maj_pos_mouton(renderer, texture[1], sheeps, wolves, interaction.get_nb_sheep(), NB_WOLF); //Display sheeps
        render_copy_maj_pos_wolf(renderer, texture[2], sheeps, shepherd_dogs, wolves, interaction.get_nb_sheep(), NB_SHEPHERD_DOG, interaction.get_nb_wolves(),&shepherd); //Display wolves
        timer = increase_nb_wolves(&interaction, timer); //Increase nb wolves for more difficulty

        if (procreate(sheeps, interaction.get_nb_sheep()) == 1)
            interaction.set_nb_sheep(interaction.get_nb_sheep() + 1);

        render_copy_shepherd(renderer, texture[3], shepherd); //Display shepherd
        render_copy_maj_pos_shepherd_dog(renderer, texture[4], shepherd_dogs, shepherd.get_x(), shepherd.get_y(), other); //Display shepherd dog
        SDL_RenderPresent(renderer); //Update screen
        SDL_Delay(10); //FPS
    }
    delete[] sheeps; delete[] wolves; delete[] other; delete[] shepherd_dogs;

    return 0;
}
