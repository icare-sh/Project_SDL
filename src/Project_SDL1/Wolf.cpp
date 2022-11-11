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


void Wolf::maj_position(Animal * sheeps,Animal *shepherd_dogs, int size_sheeps, int size_shepherd_dogs )
{
    Animal * nearest = nearest_sheep(sheeps, size_sheeps);
    Animal * nearest_dogs = are_shepherd_dogs_near(shepherd_dogs, size_shepherd_dogs);
    if(speed_up(nearest_dogs))
    {

        float temp_taux = 0.1;
        set_direction_x(nearest_dogs->get_x() + get_x());
        set_direction_y(nearest_dogs->get_y() + get_y());

        temp_taux = sqrt(pow(get_direction_x(), 2) + pow(get_direction_y(), 2));

        set_x(get_x() + get_direction_x() * get_speed()/temp_taux);
        set_y(get_y() + get_direction_y() * get_speed()/temp_taux);
    }
    else if(!kill_sheep(nearest))
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


Animal * Wolf::are_shepherd_dogs_near(Animal * shepherd_dog, int size)
{
    Animal * nearest = nullptr;
    float distance = 0;
    float temp_distance = 0;
    for (int i = 0; i < size; i++)
    {
        if (shepherd_dog[i].get_alive())
        {
            
            temp_distance = sqrt(pow(shepherd_dog[i].get_x()- get_x(), 2) + pow(shepherd_dog[i].get_y() - get_y(), 2));
            if (temp_distance < distance || distance == 0)
            {
                distance = temp_distance;
                nearest = &shepherd_dog[i];
            }
        }
    }
    return nearest;
}

int Wolf::speed_up(Animal * shepherd_dog)
{
    if(sqrt(pow(shepherd_dog[0].get_x()- get_x(), 2) + pow(shepherd_dog[0].get_y() - get_y(), 2)) < AURA_WOLF)
    {

        set_speed(SPEED_WOLF*2);
        return 1;
    }
    else
    {
        set_speed(SPEED_WOLF);
        return 0;
    }
}
