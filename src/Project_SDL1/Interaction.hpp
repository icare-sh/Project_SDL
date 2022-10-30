#include <stdlib.h>

struct properties {
    int x;
    int y;
    float speed;
    float direction_x;
    float direction_y;
};

class Interaction
{
    public:
        Interaction() = default; // default constructor
        ~Interaction() = default; // default destructor
        virtual Interaction interact() const;  // virtual function memeber

        // getter and setter
        void set_nb_sheep(int x);
        int get_nb_sheep() const;
        void set_nb_wolves(int y);
        int get_nb_wolves() const;



    private:
        int nb_sheep;
        int nb_wolves;
};
