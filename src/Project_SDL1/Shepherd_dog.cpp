#include <math.h>
#include <SDL.h>

#include "Shepherd_dog.hpp"

Shepherd_dog::Shepherd_dog()
{
    set_x(SCREEN_WIDTH/2 + rand() % 150 + 200);
    set_y(SCREEN_HEIGHT/2 + rand() % 150 + 200);
    set_speed(3);
    set_direction_x(0);
    set_direction_y(0);
    set_angle(rand() % 360);
    set_shape_size(80);
    set_is_hunting(false);

}
void Shepherd_dog::maj_position(Animal * animals,Animal * other, int _x, int _y,Shepherd * shepherd)
{
    (void)other;
    float tmp_speed = 0.02;
    int random = rand() % 5;
    float temp_taux = 0.1;
    if (random == 2)
        set_angle( get_angle() +  ORBIT_SPEED + tmp_speed);
    else
        set_angle( get_angle() +  ORBIT_SPEED);
    if(get_is_hunting())
    {
        if(get_go_hunt())
        {
            set_direction_x(get_x_hunt() - get_x());
            set_direction_y(get_y_hunt() - get_y());
            
        }
        else
        {
            set_direction_x(_x + cos(get_angle()) * ORBIT_RADIUS - get_x());
            set_direction_y(_y + sin(get_angle()) * ORBIT_RADIUS - get_y());


        }
        //Aller vers le baton
        if(get_x() > get_x_hunt() - 10 && get_x() < get_x_hunt() + 10 && get_y() > get_y_hunt() - 10 && get_y() < get_y_hunt() + 10)
            {
                set_go_hunt(false);

            }
        //retour vers le berger
        if(!get_go_hunt() && get_x() > _x + cos(get_angle()) * ORBIT_RADIUS - 10 && get_x() < _x + cos(get_angle()) * ORBIT_RADIUS + 10 && get_y() > _y + sin(get_angle()) * ORBIT_RADIUS - 10 && get_y() < _y + sin(get_angle()) * ORBIT_RADIUS + 10)
            {
                set_is_hunting(false);
            }

        temp_taux = sqrt(pow(get_direction_x(), 2) + pow(get_direction_y(), 2));
            set_x(get_x() + get_speed() * get_direction_x() / temp_taux);
            set_y(get_y() + get_speed() * get_direction_y() / temp_taux);


    }
    else
    {
        set_x(_x + cos(get_angle()) * ORBIT_RADIUS);
        set_y(_y + sin(get_angle()) * ORBIT_RADIUS);
    }
}

Shepherd_dog * Shepherd_dog::get_shepherd_dog_selection(Shepherd_dog * dogs, int x_pos_mouse ,int y_pos_mouse)
{
    for (int i = 0; i < NB_SHEPHERD_DOG; i++)
    {
        if (dogs[i].get_x() < x_pos_mouse && dogs[i].get_x() + dogs[i].get_shape_size() > x_pos_mouse)
        {
            if (dogs[i].get_y() < y_pos_mouse && dogs[i].get_y() + dogs[i].get_shape_size() > y_pos_mouse)
            {
                return &dogs[i];
            }
        }
    }
    return NULL;
}

void Shepherd_dog::set_is_hunting(bool is_hunting)
{
    this->is_hunting = is_hunting;
}

bool Shepherd_dog::get_is_hunting() const
{
    return this->is_hunting;
}

void Shepherd_dog::set_go_hunt(bool go_hunt)
{
    this->is_go_hunt = go_hunt;
}

bool Shepherd_dog::get_go_hunt() const
{
    return this->is_go_hunt;
}

void Shepherd_dog::maj_timer()
{
    
}