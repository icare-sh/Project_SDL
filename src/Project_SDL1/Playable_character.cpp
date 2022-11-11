#include "Playable_character.hpp"

int Playable_character::get_x() const
{
    return x;
}

int Playable_character::get_y() const
{
    return y;
}

float Playable_character::get_speed() const
{
    return speed;
}

float Playable_character::get_direction_x() const
{
    return direction_x;
}

float Playable_character::get_direction_y() const
{
    return direction_y;
}

void Playable_character::set_x(int x)
{
    this->x = x;
}

void Playable_character::set_y(int y)
{
    this->y = y;
}

void Playable_character::set_speed(float speed)
{
    this->speed = speed;
}

void Playable_character::set_direction_x(float direction_x)
{
    this->direction_x = direction_x;
}

void Playable_character::set_direction_y(float direction_y)
{
    this->direction_y = direction_y;
}

void Playable_character::set_shape_size(int shape_size)
{
    this->shape_size = shape_size;
}


int Playable_character::get_shape_size() const
{
    return shape_size;
}

