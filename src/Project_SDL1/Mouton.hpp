#ifndef MOUTON_HPP
#define MOUTON_HPP

#include <iostream>
#include <math.h>
#include "Animal.hpp"

class Mouton : public Animal{
    public:
        Mouton();
        ~Mouton() = default;
        void maj_position(Animal * wolves,Animal * other, int size, int size_other);
        Animal * nearest_wolf(Animal * wolfs, int size);
        int speed_up(Animal * wolf);

    
};

#endif // MOUTON_HPP
