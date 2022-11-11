#ifndef Shepherd_hpp
#define Shepherd_hpp

#include "Playable_character.hpp"

class Shepherd : public Playable_character {
    public:
        Shepherd() ;
        ~Shepherd() = default;
        void move_up();
        void move_down();
        void move_left();
        void move_right();

};


#endif /* Shepherd_hpp */
