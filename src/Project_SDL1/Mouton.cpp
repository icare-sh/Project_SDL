#include "Mouton.hpp"

Mouton::Mouton()
{
    set_x(rand()%(TAILLE_MAX_X-TAILLE_MIN_X)+TAILLE_MIN_X);
    set_y(rand()%(TAILLE_MAX_Y-TAILLE_MIN_Y)+TAILLE_MIN_Y);
    set_speed(SPEED_SHEEP);
    set_direction_x(rand() % 1000);
    set_direction_y(rand() % 1000);
    set_alive(true);
    set_shape_size(60);
    
}

Animal * Mouton::nearest_wolf(Animal * wolfs, int size)
{
    Animal * nearest = nullptr;
    float distance = 0;
    float temp_distance = 0;
    for (int i = 0; i < size; i++)
    {
        if (wolfs[i].get_alive())
        {
            
            temp_distance = sqrt(pow(wolfs[i].get_x()- get_x(), 2) + pow(wolfs[i].get_y() - get_y(), 2));
            if (temp_distance < distance || distance == 0)
            {
                distance = temp_distance;
                nearest = &wolfs[i];
            }
        }
    }
    return nearest;
}


int Mouton::speed_up(Animal * wolf)
{
    printf("distance : %f\n", sqrt(pow(wolf[0].get_x()- get_x(), 2) + pow(wolf[0].get_y() - get_y(), 2)));
    if(sqrt(pow(wolf[0].get_x()- get_x(), 2) + pow(wolf[0].get_y() - get_y(), 2)) < AURA_MOUTON)
    {

        set_speed(SPEED_SHEEP*3);
        set_direction_x(wolf[0].get_direction_x());
        set_direction_y(wolf[0].get_direction_y());
        return 1;
    }
    else
    {
        set_speed(SPEED_SHEEP);
        return 0;
    }
}

void Mouton::maj_position(Animal * wolves,Animal * other,int size, int size_other)
{

    (void)other;
    float temp_taux = 0.1;
    Animal * nearest = nearest_wolf(wolves, size);
    speed_up(nearest);

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
