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
        void maj_position(Animal * animals,Animal * other, int _x, int _y,Shepherd * shepherd);
        Shepherd_dog * get_shepherd_dog_selection(Shepherd_dog * dogs, int x_pos_mouse ,int y_pos_mouse);
        //set and get is hunting
        void set_is_hunting(bool is_hunting);
        bool get_is_hunting() const;
        void set_x_go_hunt(int x);
        void set_y_go_hunt(int y);
       
      
    private:
        bool is_hunting;
        //int x_hunting;
        //int y_hunting;
        int x_go_hunt;
        int y_go_hunt;
};



#endif  // SHEPHERD_DOG_HPP
