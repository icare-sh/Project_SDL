#include <stdio.h>
#include <string>
#include <SDL.h>

#include "Project_SDL1.hpp"




int main(int argc, char* argv[])
{  
    if (argc != 3)
    {
        printf("Usage: %s <NB Sheeps> <NB Wolves>\n", argv[0]);
        return 1;
    }

    SDL_Window *window = NULL; // Declare a window
    SDL_Renderer *renderer = NULL; // Declare a renderer
    SDL_Texture **texture = NULL; // Declare a list of texture
    SDL_Surface *surface = NULL; // Declare a surface
    Application app;
    Interaction interaction;

    interaction.set_nb_sheep(atoi(argv[1]));
    interaction.set_nb_wolves(atoi(argv[2]));

    int nb_texture = 9; // Number of texture

    texture = new SDL_Texture*[nb_texture];
    texture[0] = NULL; // Declare texture for background
    texture[1] = NULL; // Declare texture for sheep
    texture[2] = NULL; // Declare texture for wolves
    texture[3] = NULL; // Declare texture for shepherd
    texture[4] = NULL; // Declare texture for dogs
    texture[5] = NULL; // Declare texture for sheep female
    texture[6] = NULL; // Declare texture for sheep in love
    texture[7] = NULL; // Declare texture for background win
    texture[8] = NULL; // Declare texture for background loose
    
    

    // Initialize SDL, create a window and set the renderer
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    else
    {
        //create window
        window = app.create_window("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);
        renderer = app.create_renderer(window);
        game(window, renderer, texture, surface, interaction);
    }
    
    app.SDL_close(window, nb_texture, texture, renderer);
    
    delete[] texture;
    return 0;
}
