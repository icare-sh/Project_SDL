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
}

void Shepherd_dog::maj_position(Animal * animals,Animal * other, int _x, int _y )
{
    (void)other;
    float tmp_speed = 0.02;
    int random = rand() % 5;

    if (random == 2)
        set_angle( get_angle() +  ORBIT_SPEED + tmp_speed);
    else
        set_angle( get_angle() +  ORBIT_SPEED);
    set_x(_x + cos(get_angle()) * ORBIT_RADIUS);
    set_y(_y + sin(get_angle()) * ORBIT_RADIUS);
}
