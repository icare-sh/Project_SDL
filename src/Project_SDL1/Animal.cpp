#include "Animal.hpp"

int Animal::get_x() const
{
    return x;
}

int Animal::get_y() const
{
    return y;
}

float Animal::get_speed() const
{
    return speed;
}

float Animal::get_direction_x() const
{
    return direction_x;
}

float Animal::get_direction_y() const
{
    return direction_y;
}

bool Animal::get_alive() const
{
    return alive;
}

void Animal::set_x(int x)
{
    this->x = x;
}

void Animal::set_y(int y)
{
    this->y = y;
}

void Animal::set_speed(float speed)
{
    this->speed = speed;
}

void Animal::set_direction_x(float direction_x)
{
    this->direction_x = direction_x;
}

void Animal::set_direction_y(float direction_y)
{
    this->direction_y = direction_y;
}

void Animal::set_alive(bool alive)
{
    this->alive = alive;
}

void Animal::set_shape_size(int shape_size)
{
    this->shape_size = shape_size;
}

int Animal::get_shape_size() const
{
    return shape_size;
}

void Animal::set_angle(float angle)
{
    this->angle = angle;
}

float Animal::get_angle() const
{
    return angle;
}

void Animal::set_gender(Gender g)
{
    this->g = g;
}

Gender Animal::get_gender() const
{
    return g;
}

void Animal::set_timer(int timer)
{
    this->timer = timer;
}

int Animal::get_timer() const
{
    return timer;
}

void Animal::set_time(bool time)
{
    this->time = time;
}

bool Animal::get_time() const
{
    return time;
}

void Animal::set_x_hunt(int x)
{
    this->x_hunt = x;
}

int Animal::get_x_hunt() const
{
    return x_hunt;
}

void Animal::set_y_hunt(int y)
{
    this->y_hunt = y;
}

int Animal::get_y_hunt() const
{
    return y_hunt;
}