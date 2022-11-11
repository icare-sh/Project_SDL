#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Application.hpp"

#define TAILLE_MAX_X 1613 //limit of sheepfold
#define TAILLE_MAX_Y 868 //limit of sheepfold
#define TAILLE_MIN_X 230 //limit of sheepfold
#define TAILLE_MIN_Y 180 //limit of sheepfold
#define SCREEN_WIDTH 1920 //screen width
#define SCREEN_HEIGHT 1080 //screen height
#define AURA_KILL 35 //aura of the wolf to kill the sheep
#define SPEED_SHEEP 2 //speed of the sheep
#define SPEED_WOLF 2 //speed of the wolf
#define AURA_MOUTON 150 //aura of the wolf to follow the sheep
#define AURA_WOLF 300 //aura of the wolf to run away from the shepherd dog
#define ORBIT_SPEED 0.005f //speed of the shepherd dog
#define ORBIT_RADIUS 170.0f //radius of the shepherd dog
#define AURA_PROCREATION 5 //aura of the sheep to procreate 

class Display : public Application {
    public:
        Display() = default;
        ~Display() = default;

        /*
        * @brief Create a Surface
        * Description: Create a Surface with the given parameters
        * return: a Surface
        */
        SDL_Surface* load_surface(const char* path);

        /*
        * @brief Create a Texture
        * Description: Create a Texture with the given parameters
        * return: a Texture
        */
        SDL_Texture* create_texture(SDL_Surface* surface, SDL_Renderer* renderer);

        /*
        * @brief load image
        * Description: load image with the given parameters
        * return: a Texture
        */
        SDL_Texture* load_image(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Surface* surface, const char* path);

    private:
        const char *path;
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        SDL_Surface* surface;
};

#endif // DISPLAY_HPP
