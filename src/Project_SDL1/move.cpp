#include <iostream>
#include <math.h>

#include "move.hpp"

#define SHAPE_SIZE 60


properties * render_copy(SDL_Renderer* renderer, SDL_Texture* texture, int size)
{
    properties *prop = new properties[size];
    for (int i = 0; i < size; i++)
    {
        // Set the position randomly around the center of the screen
        SDL_Rect SrcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
        SDL_Rect DestR = { (rand()%1000) / 2 - SHAPE_SIZE / 2 , (rand()%600) / 2 - SHAPE_SIZE / 2 , SHAPE_SIZE, SHAPE_SIZE};
        prop[i].x = DestR.x;
        prop[i].y = DestR.y;
        prop[i].speed = 2;
        prop[i].direction_x = rand() % 800;
        prop[i].direction_y = rand() % 600;


        
        SDL_RenderCopy(renderer, texture, &SrcR, &DestR);

    }
    
    return prop; // return a list of properties
}

properties * render_copy_maj_pos(SDL_Renderer* renderer, SDL_Texture* texture, properties *prop, int size)
{
    float temp_taux = 0.1;
    for (int i = 0; i < size; i++)
    {
        SDL_Rect SrcR = {0,0, SHAPE_SIZE, SHAPE_SIZE};
        temp_taux = sqrt(pow(prop[i].direction_x, 2) + pow(prop[i].direction_y, 2));
        
        if (prop[i].x + prop[i].speed * prop[i].direction_x / temp_taux < 0 || prop[i].x + prop[i].speed * prop[i].direction_x / temp_taux > 1200 - SHAPE_SIZE)
        {
            prop[i].direction_x = -prop[i].direction_x;
        }
        if (prop[i].y + prop[i].speed * prop[i].direction_y / temp_taux < 0 || prop[i].y + prop[i].speed * prop[i].direction_y / temp_taux > 1000 - SHAPE_SIZE)
        {
            prop[i].direction_y = -prop[i].direction_y;
        }
        prop[i].x += prop[i].speed * prop[i].direction_x / temp_taux;
        prop[i].y += prop[i].speed * prop[i].direction_y / temp_taux;
        SDL_Rect DestR = {prop[i].x, prop[i].y, SHAPE_SIZE, SHAPE_SIZE};
        SDL_RenderCopy(renderer, texture, &SrcR, &DestR);
    }
    
    return prop; // return a list of properties
}

properties * present_image_and_clear(SDL_Renderer* renderer, SDL_Texture* texture, properties *prop, int size)
{

    //SDL_RenderClear(renderer);
    prop = render_copy_maj_pos(renderer, texture, prop, size);

    return prop;
}
