#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <math.h>
#include "Display.hpp"

class Animal : public Display{
    public:
        Animal() = default;
        ~Animal() = default;
        /*
        * @brief: get the x position of the animal
        */
        int get_x() const;

        /*
        * @brief: get the y position of the animal
        */
        int get_y() const;

        /*
        * @brief: get the speed of the animal
        */
        float get_speed() const;

        /*
        * @brief: get the direction x of the animal
        */
        float get_direction_x() const;

        /*
        * @brief: get the direction y of the animal
        */
        float get_direction_y() const;

        /*
        * @brief: get a bool to know if the animal is alive
        */
        bool get_alive() const;

        /*
        * @brief: set the x position of the animal
        */ 
        void set_x(int x);

        /*
        * @brief: set the y position of the animal
        */
        void set_y(int y);

        /*
        * @brief: set the speed of the animal
        */
        void set_speed(float speed);

        /*
        * @brief: set the direction x of the animal
        */
        void set_direction_x(float direction_x);

        /*
        * @brief: set the direction y of the animal
        */
        void set_direction_y(float direction_y);

        /*
        * @brief: set the alive of the animal
        */
        void set_alive(bool alive);

        /*
        * @brief: set the shape size of the animal
        */
        void set_shape_size(int shape_size);

        /*
        * @brief: get the shape size of the animal
        */
        int get_shape_size() const;

        float get_angle() const;

        void set_angle(float angle);
        
        /*
        * @brief: an abstract function to update the position of the animal
        */
        virtual void maj_position(Animal * animals,Animal * other, int size_animals, int size_other ) = 0;
    private:
        int x;
        int y;
        float speed;
        float direction_x;
        float direction_y;
        bool alive;
        int shape_size;
        float angle;
       
};

#endif // ANIMAL_HPP
