#ifndef MOUTON_HPP
#define MOUTON_HPP

#include <iostream>
#include <math.h>
#include "Animal.hpp"

class Mouton : public Animal{
    public:
        Mouton();
        ~Mouton() = default;
        /*
        * @brief: Maj position of the sheep
        *
        * @param: wolves: a array of wolves
        * @param: other: other animal
        * @param: size: size of the wolves array
        * @param: size_other: size of the other array
        */
        void maj_position(Animal * wolves,Animal * other, int size, int size_other);

        /*
        * @brief: Find the nearest wolf
        *
        * @param: wolfs: a array of wolves
        * @param: size: the size of the array
        * @return: the nearest wolves
        */
        Animal * nearest_wolf(Animal * wolfs, int size);

        /*
        * @brief: Speed up the sheep if it is near a wolf
        *
        * @param: wolf: the nearest wolf
        * @return: 1 if the sheep is near a wolf
        */
        int speed_up(Animal * wolf);



};


/*
* @brief: Procreate new sheep
*/
int procreate(Animal * moutons, int size);


/*
* @brief: update timer to make mouton pregnant
*/

int maj_timer(Animal * mouton, bool time);

#endif // MOUTON_HPP
