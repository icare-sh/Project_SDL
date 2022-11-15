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


void render_copy(SDL_Renderer *renderer, SDL_Texture *texture, Animal * animals)
{
    //Size of the texture
    SDL_Rect SrcR = {0, 0, animals->get_shape_size(), animals->get_shape_size()};
    //Position of the texture
    SDL_Rect DestR = { animals->get_x() , animals->get_y()  , animals->get_shape_size(), animals->get_shape_size()};
    //Copy the texture to the renderer
    SDL_RenderCopy(renderer, texture, &SrcR , &DestR); 
}

//Maj position of one class Animal


//Maj position of sheeps
void render_copy_maj_pos_mouton(SDL_Renderer *renderer, SDL_Texture *texture, Animal * sheeps,Animal * wolfs, int size_sheeps, int size_wolfs,SDL_Texture *texture2,SDL_Texture *texture3)
{
    //delete the sheep if alive == false
    
    for (int i = 0; i < size_sheeps; i++)
    {
        if(sheeps[i].get_alive() == true)
        {
            maj_timer(&sheeps[i],sheeps[i].get_time());
            sheeps[i].maj_position(wolfs,NULL,size_wolfs,NULL,NULL);
            if(sheeps[i].get_gender() == MALE)
            {
                render_copy(renderer,texture,&sheeps[i]);

            }
            else
            {
                if(sheeps[i].get_time())
                {
                    render_copy(renderer,texture2,&sheeps[i]);
                }
                else
                {
                    render_copy(renderer,texture3,&sheeps[i]);
                }


            }        
        
        }
        else
        {
            sheeps[i].~Animal();
        }
    }

}

//Maj position of wolfs
void render_copy_maj_pos_wolf(SDL_Renderer *renderer, SDL_Texture *texture, Animal * wolf,Animal * dog, Animal *sheeps, int size_wolf, int size_dog, int size_sheeps,Shepherd * shepherd)
{
    //delete the sheep if alive == false
    
    for (int i = 0; i < size_wolf; i++)
    {
        if(wolf[i].get_alive() == true)
        {
        maj_timer(&wolf[i],wolf[i].get_time());
        wolf[i].maj_position(sheeps,dog,size_sheeps,size_dog,shepherd);
        render_copy(renderer,texture,&wolf[i]);
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
void render_copy_maj_pos_shepherd_dog(SDL_Renderer *renderer, SDL_Texture *texture, Animal  * dog, int x, int y)
{
    for (int i = 0; i < NB_SHEPHERD_DOG; i++)
    {
        dog[i].maj_position(dog,NULL, x,y,NULL);
        render_copy(renderer,texture,&dog[i]);
    }
}

void get_shepherd_direction(SDL_Event event, Shepherd *shepherd)

{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_z:
                shepherd->move_up();
                break;
            case SDLK_s:
                shepherd->move_down();
                break;
            case SDLK_q:
                shepherd->move_left();
                break;
            case SDLK_d:
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

    Interaction interaction;

    srand (time (NULL)); //reset random

    SDL_bool shouldStop = SDL_FALSE; // Bool For loop condition;

    Display display; //Call display class

    texture[0] = display.load_image(renderer, "media/background.bmp"); //load background image
    texture[1] = display.load_image(renderer, "media/sheep1.bmp"); //Load image with path of img
    texture[2] = display.load_image(renderer, "media/wolf1.bmp"); //Load wolf image
    texture[3] = display.load_image(renderer, "media/Berger.bmp"); //Load shepherd image
    texture[4] = display.load_image(renderer, "media/dog.bmp"); //Load shepherd dog image
    texture[5] = display.load_image(renderer, "media/sheep_femme.bmp"); //Load shepherd dog image
    texture[6] = display.load_image(renderer, "media/sheep_femme_amoureuse.bmp"); //Load shepherd dog image
    texture[7] = display.load_image(renderer, "media/background_win.bmp"); //load background image
    texture[8] = display.load_image(renderer, "media/background_loose.bmp"); //load background image

    Mouton * sheeps = create_sheeps(); //Create NB_SHEPP of sheeps & init position
    Wolf * wolves = create_wolves(); //Create NB_WOLF of wolves & init position
    Shepherd_dog  * shepherd_dogs = create_shepherd_dog(); //Call shepherd_dog class
    Shepherd_dog * shepherd_dog_selection = new Shepherd_dog();
    auto shepherd = Shepherd(); //Call shepherd class

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
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        shepherd_dog_selection = shepherd_dogs->get_shepherd_dog_selection(shepherd_dogs, event.button.x, event.button.y);
                    }
                    if(event.button.button == SDL_BUTTON_RIGHT)
                    {
                        if (shepherd_dog_selection != NULL)
                        {

                            shepherd_dog_selection->set_x_hunt(event.button.x);
                            shepherd_dog_selection->set_y_hunt(event.button.y);
                            shepherd_dog_selection->set_is_hunting(true);
                            shepherd_dog_selection->set_go_hunt(true);
                            shepherd_dog_selection = NULL;

                        }
                    }
                    
                    break;
                
                default:
                    break;
             }
        }
        
        SDL_RenderCopy(renderer, texture[0], NULL, NULL); //Display background
        render_copy_maj_pos_mouton(renderer, texture[1], sheeps, wolves, interaction.get_nb_sheep(), NB_WOLF,texture[5],texture[6]); //Display sheeps
        render_copy_maj_pos_wolf(renderer, texture[2], wolves , shepherd_dogs,sheeps ,interaction.get_nb_wolves() , NB_SHEPHERD_DOG,interaction.get_nb_sheep() ,&shepherd); //Display wolves
        timer = increase_nb_wolves(&interaction, timer); //Increase nb wolves for more difficulty
        render_copy_maj_pos_shepherd_dog(renderer, texture[4], shepherd_dogs, shepherd.get_x(), shepherd.get_y()); //Display shepherd dog
        
        render_copy_shepherd(renderer, texture[3], shepherd); //Display shepherd

        if (procreate(sheeps, interaction.get_nb_sheep()) == 1)
            interaction.set_nb_sheep(interaction.get_nb_sheep() + 1);

        SDL_RenderPresent(renderer); //Update screen
        SDL_Delay(10); //FPS

    }


    



    delete[] sheeps; delete[] wolves; delete[] shepherd_dogs; delete[] shepherd_dog_selection;

    return 0;
}
