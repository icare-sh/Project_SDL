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
    set_timer(TIME_TO_DIE);
    set_time(false);
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


void Wolf::maj_position(Animal * sheeps,Animal *shepherd_dogs, int size_sheeps, int size_shepherd_dogs,Shepherd * shepherd)
{
    Animal * nearest = nearest_sheep(sheeps, size_sheeps);
    Animal * nearest_dogs = are_shepherd_dogs_near(shepherd_dogs, size_shepherd_dogs);
    
    if(speed_up(nearest_dogs))
    {

        
        float temp_taux = 0.1;
        set_direction_x(-(shepherd->get_x() - get_x()));
        set_direction_y(-(shepherd->get_y() - get_y()));

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
    } else if (kill_sheep(nearest))
    {
        set_timer(TIME_TO_DIE); // reset timer to die
    }
}

int Wolf::kill_sheep(Animal * sheep)
{
    if(sqrt(pow(sheep[0].get_x()- get_x(), 2) + pow(sheep[0].get_y() - get_y(), 2)) < AURA_KILL)
    {
        sheep[0].set_alive(false);
        return 1; // sheep killed
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

        set_speed(SPEED_WOLF*4);
        return 1;
    }
    else
    {
        set_speed(SPEED_WOLF);
        return 0;
    }
}

void dont_touch(Animal * wolves, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (wolves[i].get_alive())
        {
            for (int j = 0; j < size; j++)
            {
                if (wolves[j].get_alive() && i != j)
                {
                    if(sqrt(pow(wolves[i].get_x()- wolves[j].get_x(), 2) + pow(wolves[i].get_y() - wolves[j].get_y(), 2)) < 100)
                    {
                        float temp_taux = 0.1;

                        temp_taux = sqrt(pow(wolves[i].get_direction_x(), 2) + pow(wolves[i].get_direction_y(), 2));

                        wolves[i].set_x(wolves[i].get_x() + (rand() % 100 + 1) * wolves[i].get_speed()/temp_taux);
                        wolves[i].set_y(wolves[i].get_y() + (rand() % 100 + 1) * wolves[i].get_speed()/temp_taux);
                    }
                }
            }
        }
    }
}

void Wolf::maj_timer()
{
   this->set_timer(this->get_timer() - 1);
}

void check_if_time_is_over(Animal * wolve)
{
    if(wolve->get_timer() <= 0 && wolve->get_alive())
    {
        wolve->set_time(true);
        wolve->set_alive(false);
    }
}
