#include "Wolf.hpp"

Wolf::Wolf()
{
    set_x(rand()%SCREEN_WIDTH);
    set_y(0);
    set_speed(3);
    set_direction_x(0);
    set_direction_y(0);
    set_alive(true);
    set_shape_size(70);
}


Animal * Wolf::nearest_sheep(Animal * sheeps, int size)
{
    Animal * nearest = nullptr;
    float distance = 0;
    float temp_distance = 0;
    for (int i = 0; i < size; i++)
    {
        if (sheeps[i].get_alive())
        {
            
            temp_distance = sqrt(pow(sheeps[i].get_x()- get_x(), 2) + pow(sheeps[i].get_y() - get_y(), 2));
            if (temp_distance < distance || distance == 0)
            {
                distance = temp_distance;
                nearest = &sheeps[i];
            }
        }
    }
    return nearest;
}


void Wolf::maj_position(Animal * sheeps,Animal *other, int size_animal, int size_other )
{

    (void)other;
    (void)size_other;
    Animal * nearest = nearest_sheep(sheeps, size_animal);
        if(!kill_sheep(nearest))
        {
            float temp_taux = 0.1;
            set_direction_x(nearest->get_x() - get_x());
            set_direction_y(nearest->get_y() - get_y());

            temp_taux = sqrt(pow(get_direction_x(), 2) + pow(get_direction_y(), 2));

            set_x(get_x() + get_direction_x() * get_speed()/temp_taux);
            set_y(get_y() + get_direction_y() * get_speed()/temp_taux);
        }
}

int Wolf::kill_sheep(Animal * sheep)
{
    if(sqrt(pow(sheep[0].get_x()- get_x(), 2) + pow(sheep[0].get_y() - get_y(), 2)) < AURA_KILL)
    {
        sheep[0].set_alive(false);
        return 1;
    }
    return 0;
}

