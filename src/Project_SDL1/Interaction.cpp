#include <iostream>
#include "Interaction.hpp"

// getter and setter
void Interaction::set_nb_sheep(int x)
{
    nb_sheep = x;
}

int Interaction::get_nb_sheep() const
{
    return nb_sheep;
}

void Interaction::set_nb_wolves(int y)
{
    nb_wolves = y;
}

int Interaction::get_nb_wolves() const
{
    return nb_wolves;
}

