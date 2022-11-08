#include <iostream>
#include <math.h>
#include "Display.hpp"

class Animal : public Display{
    public:
        Animal() = default;
        ~Animal() = default;
        int get_x() const;
        int get_y() const;
        float get_speed() const;
        float get_direction_x() const;
        float get_direction_y() const;
        bool get_alive() const;
        void set_x(int x);
        void set_y(int y);
        void set_speed(float speed);
        void set_direction_x(float direction_x);
        void set_direction_y(float direction_y);
        void set_alive(bool alive);
        void set_shape_size(int shape_size);
        int get_shape_size() const;
        virtual void maj_position() = 0;
    private:
        int x;
        int y;
        float speed;
        float direction_x;
        float direction_y;
        bool alive;
        int shape_size;
       
};
