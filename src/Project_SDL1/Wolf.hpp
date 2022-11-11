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
        void maj_position(Animal * sheeps,Animal *shepherd_dogs, int size_sheeps, int size_shepherd_dogs );

        /*
        * @brief: Find the nearest sheep
        *
        * @param: sheeps: array of sheep
        * @param: size: size of the array sheeps
        * @return: the nearest sheep
        */
        Animal * nearest_sheep(Animal * sheeps, int size);

        /*
        * @brief: find the nearest dog
        *
        * @param: dogs: array of dogs
        * @param: size: size of the array dogs
        * @return: the nearest dog
        */
        Animal * are_shepherd_dogs_near(Animal * shepherd_dog, int size);

        /*
        * @brief: Speed up the wolf if it is near a dog
        *
        * @param: dog: the nearest dog
        * @return: 1 if the wolf is near a dog
        */
        int speed_up(Animal * shepherd_dog);

        /*
        * @brief: Check if the sheep could be killed and kill it
        *
        * @param: sheeps: array of sheep
        * @return: 1 if sheep is killed
        */
        int kill_sheep(Animal * sheep);

        int dont_touch(Animal * wolves, int size);
};
#endif // WOLF_HPP
