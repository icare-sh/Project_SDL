#include  "Shepherd.hpp"

Shepherd::Shepherd()
{
    set_x(SCREEN_WIDTH/2);
    set_y(SCREEN_HEIGHT/2);
    set_speed(10);
    set_direction_x(0);
    set_direction_y(0);
    set_shape_size(100);
}

void Shepherd::move_up()
{
    set_direction_y(-1);
    set_y(get_y() + get_direction_y() * get_speed());
}

void Shepherd::move_down()
{
    set_direction_y(1);
    set_y(get_y() + get_direction_y() * get_speed());
}

void Shepherd::move_left()
{
    set_direction_x(-1);
    set_x(get_x() + get_direction_x() * get_speed());
}

void Shepherd::move_right()
{
    set_direction_x(1);
    set_x(get_x() + get_direction_x() * get_speed());
}



