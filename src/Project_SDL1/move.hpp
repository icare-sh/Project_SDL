#include "rendered_obj.hpp"

class move: public rendered_obj {
    public:
        move() = default;
        ~move() = default;
};

/*
* Create X Sheeps from Interaction class and render them
* Description: Create X Sheeps from Interaction class and render them
* return: a vector of sheeps
*/
properties * render_copy(SDL_Renderer* renderer, SDL_Texture* texture, int size);

/*
* Move animals and render them
* return: a list of animals and their properties
*/
properties * render_copy_maj_pos(SDL_Renderer* renderer, SDL_Texture* texture, properties *prop, int size);

/*
* Present the image and clear the renderer
* return: a list of animals and their properties
*/
properties * present_image_and_clear(SDL_Renderer* renderer, SDL_Texture* texture, properties *prop, int size);

