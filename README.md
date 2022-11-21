# Project_SDL
This is a game in C++ using SDL library

insert image in te readme.md file in github repository using markdown syntax as follows: 
    
![Alt text(asset/background.png?raw=true "Optional Title")]







## Build
Create a build directory and run cmake and make from there
```bash
    mkdir build
    cd build
    cmake ..
    make
```
## Run
```bash
    ./src/Project_SDL1/SDL_Project <nb_sheeps> <nb_wolves>  
```  
You have to set the number of sheeps and wolves you want to play with.  

## Gameplay
* The wolves are controlled by the computer and will try to eat the sheeps.  
* The sheeps are controlled by the computer also and will try to escape the wolves.  
* You can control the shepherd with the q, d, z, s keys.  
* The shepherd dogs move circles around the shepherd, you can control them by left clicking on the screen to select one of them and right clicking in the screen to move them to the selected position.  
  
  
The game ends when all the sheeps are eaten or when the wolves are all dead.
