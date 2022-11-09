#ifndef WOLF_HPP
#define WOLF_HPP

#include <iostream>
#include "Animal.hpp"
#include <vector>



class Wolf : public Animal{
    public:
        Wolf();
        ~Wolf() = default;
        void maj_position(Animal * sheeps,Animal * other,int size_animal, int size_other);
        Animal * nearest_sheep(Animal * sheeps, int size);
        int kill_sheep(Animal * sheep);
};
#endif // WOLF_HPP
