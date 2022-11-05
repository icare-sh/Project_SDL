#include <SDL.h>
#include <iostream>
#include <vector>

class Application {
    public:
        Application() = default;
        ~Application() = default;
        SDL_Window* create_window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        SDL_Renderer* create_renderer(SDL_Window* window);
        void SDL_close(SDL_Window* window, int nb_texture, SDL_Texture** texture, SDL_Renderer* renderer);

    private:
        char *title;
        int xpos;
        int ypos;
        int width;
        int height;
        bool fullscreen;
        SDL_Window* window;

};

