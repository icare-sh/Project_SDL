#include "rendered_obj.hpp"


class move: public rendered_obj {
    public:
        move() = default;
        ~move() = default;
        Interaction interact() const override;
};



