#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Application.hpp"
#define TAILLE_MAX_X 1613
#define TAILLE_MAX_Y 868    
#define TAILLE_MIN_X 230
#define TAILLE_MIN_Y 180
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define AURA_KILL 35
#define SPEED_SHEEP 2
#define SPEED_WOLF 2
#define AURA_MOUTON 150 
#define AURA_WOLF 300
#define ORBIT_SPEED 0.005f
#define ORBIT_RADIUS 170.0f

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
