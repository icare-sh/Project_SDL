#include <iostream>
#include <math.h>

#include "move.hpp"

#define SHAPE_SIZE 70


properties * render_copy(SDL_Renderer* renderer, SDL_Texture* texture, int size)
{
    properties *prop = new properties[size];
    for (int i = 0; i < size; i++)
    {
        SDL_Rect SrcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
        SDL_Rect DestR = { (rand()%1920) / 2 - SHAPE_SIZE / 2 , (rand()%1080) / 2 - SHAPE_SIZE / 2 , SHAPE_SIZE, SHAPE_SIZE};
        prop[i].x = DestR.x;
        prop[i].y = DestR.y;
        prop[i].speed = 2;
        prop[i].direction_x = rand() % 10;
        prop[i].direction_y = rand() % 10;
        SDL_RenderCopy(renderer, texture, &SrcR, &DestR);

    }
    
    return prop; // return a list of properties
}

properties * render_copy_maj_pos(SDL_Renderer* renderer, SDL_Texture* texture, properties *prop, int size)
{
    float temp_taux = 0.1;
    for (int i = 0; i < size; i++)
    {
        SDL_Rect SrcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
        temp_taux = sqrt(pow(prop[i].direction_x, 2) + pow(prop[i].direction_y, 2));
        
        SDL_Rect DestR = { int(prop[i].x + prop[i].speed * prop[i].direction_x / temp_taux), int(prop[i].y + prop[i].speed * prop[i].direction_y / temp_taux) , SHAPE_SIZE, SHAPE_SIZE};
        prop[i].x = DestR.x;
        prop[i].y = DestR.y;
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
