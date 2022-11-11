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
    set_angle( get_angle() +  ORBIT_SPEED);
    set_x(_x + cos(get_angle()) * ORBIT_RADIUS);
    set_y(_y + sin(get_angle()) * ORBIT_RADIUS);
}


/*void Shepherd_dog::move(Animal * dogs,Shepherd shepherd, int size)
{
  
    dogs[0].set_x(SCREEN_WIDTH/2 + cos(dogs[0].get_angle()) * ORBIT_RADIUS);
    dogs[0].set_y(SCREEN_HEIGHT/2 + sin(dogs[0].get_angle()) * ORBIT_RADIUS);
    dogs[0].set_angle(dogs[0].get_angle() + ORBIT_SPEED);

}
*/
/*set_angle( get_angle() +  ORBIT_SPEED * 0.01f);
    set_x(shepherd.get_x() + cos(get_angle()) * ORBIT_RADIUS);
    set_y(shepherd.get_y() + sin(get_angle()) * ORBIT_RADIUS);*/
