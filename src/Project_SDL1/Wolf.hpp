#ifndef WOLF_HPP
#define WOLF_HPP

#include <iostream>
#include "Animal.hpp"
#include <vector>



class Wolf : public Animal{
    public:
        Wolf();
        ~Wolf() = default;
        /*
        * @brief: Maj position of the wolf
        *
        * @param: animals: array of sheep
        * @param: other: array of dogs
        * @param: size: size of the array animals
        * @param: size_other: size of the array other
        */
        void maj_position(Animal * sheeps,Animal * other,int size_animal, int size_other);

        /*
        * @brief: Find the nearest sheep
        *
        * @param: sheeps: array of sheep
        * @param: size: size of the array sheeps
        * @return: the nearest sheep
        */
        Animal * nearest_sheep(Animal * sheeps, int size);

        /*
        * @brief: Check if the sheep could be killed and kill it
        *
        * @param: sheeps: array of sheep
        * @return: 1 if sheep is killed
        */
        int kill_sheep(Animal * sheep);
};
#endif // WOLF_HPP
