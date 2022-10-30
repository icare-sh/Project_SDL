#include <iostream>

#include "Interaction.hpp"

// Set number of sheep
void Interaction::set_nb_sheep(int x)
{
    nb_sheep = x;
}

// Get number of sheep
int Interaction::get_nb_sheep() const
{
    return nb_sheep;
}

// Set number of wolves
void Interaction::set_nb_wolves(int y)
{
    nb_wolves = y;
}

// Get number of wolves
int Interaction::get_nb_wolves() const
{
    return nb_wolves;
}

