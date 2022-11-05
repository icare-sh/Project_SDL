#include "Application.hpp"

class Display : public Application {
    public:
        Display() = default;
        ~Display() = default;
        SDL_Surface* load_surface(const char* path);
        SDL_Texture* create_texture(SDL_Surface* surface, SDL_Renderer* renderer);
        SDL_Texture* load_image(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Surface* surface, const char* path);
    private:
        const char *path;
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        SDL_Surface* surface;
};
