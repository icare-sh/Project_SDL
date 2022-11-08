#include "Mouton.hpp"

Mouton::Mouton()
{
    set_x(rand()%(TAILLE_MAX_X-TAILLE_MIN_X)+TAILLE_MIN_X);
    set_y(rand()%(TAILLE_MAX_Y-TAILLE_MIN_Y)+TAILLE_MIN_Y);
    set_speed(2);
    set_direction_x(rand() % 1000);
    set_direction_y(rand() % 1000);
    set_alive(true);
    set_shape_size(60);
    
}

void Mouton::maj_position()
{
    float temp_taux = 0.1;
    if (get_x()  < TAILLE_MIN_X )
    {
        set_direction_x(rand() % 1000);
    }

    if(get_x() > TAILLE_MAX_X)
    {
        set_direction_x(-rand() % 1000);
    }

    if (get_y() < TAILLE_MIN_Y)
    {
        set_direction_y(rand() % 1000);
    }

    if(get_y() > TAILLE_MAX_Y)
    {
        set_direction_y(-rand() % 1000);
    }
    temp_taux = sqrt(pow(get_direction_x(), 2) + pow(get_direction_y(), 2));

    set_x(get_x() + get_speed() * get_direction_x() / temp_taux);
    set_y(get_y() + get_speed() * get_direction_y() / temp_taux);

}
