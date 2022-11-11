#ifndef SHEPHERD_DOG_HPP
#define SHEPHERD_DOG_HPP

#include "Animal.hpp"
#include "Shepherd.hpp"

class Shepherd_dog : public Animal {
    public:
        Shepherd_dog();
        ~Shepherd_dog() = default;
        /*
        * @brief: Maj position of the sheep
        *
        * @param: wolves: a array of wolves
        * @param: other: other animal
        * @param: size: size of the wolves array
        * @param: size_other: size of the other array
        */
        void maj_position(Animal * animals,Animal * other, int _x, int _y);
};

#endif  // SHEPHERD_DOG_HPP
