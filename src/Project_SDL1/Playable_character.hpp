#ifndef Playable_character_hpp
#define Playable_character_hpp

#include "Display.hpp"

class Playable_character : public Display {

    public:
        Playable_character() = default;
        ~Playable_character() = default;
    virtual void move_up() = 0;
    virtual void move_down() = 0;
    virtual void move_left() = 0;
    virtual void move_right() = 0;

     /*
        * @brief: get the x position of the player
        */
        int get_x() const;

        /*
        * @brief: get the y position of the player
        */
        int get_y() const;

        /*
        * @brief: get the speed of the player
        */
        float get_speed() const;

        /*
        * @brief: get the direction x of the player
        */
        float get_direction_x() const;

        /*
        * @brief: get the direction y of the player
        */
        float get_direction_y() const;

        /*
        * @brief: set the x position of the player
        */ 
        void set_x(int x);

        /*
        * @brief: set the y position of the player
        */
        void set_y(int y);

        /*
        * @brief: set the speed of the player
        */
        void set_speed(float speed);

        /*
        * @brief: set the direction x of the player
        */
        void set_direction_x(float direction_x);

        /*
        * @brief: set the direction y of the player
        */
        void set_direction_y(float direction_y);

        /*
        * @brief: set the shape size of the player
        */
        void set_shape_size(int shape_size);

        /*
        * @brief: get the shape size of the player
        */
        int get_shape_size() const;

    private:
        int x;
        int y;
        float speed;
        float direction_x;
        float direction_y;
        int shape_size;
};


#endif /* Playable_character_hpp */
