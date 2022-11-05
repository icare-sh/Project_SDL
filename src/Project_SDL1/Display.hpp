#include "Application.hpp"

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
