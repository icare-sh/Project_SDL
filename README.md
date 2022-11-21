# Project_SDL
This is a game in C++ using SDL library

insert image in te readme.md file in github repository using markdown syntax as follows: 
    

<img src="/asset/background.png">




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
<img src="/src/media/wolf1.bmp" >

* The sheeps are controlled by the computer also and will try to escape the wolves.  
We have two types of sheeps:  
    * The men sheep:  
    <img src="/src/media/sheep1.bmp" >  


    * The women sheep:  
    <img src="/src/media/sheep_femme.bmp" >  


    * The women have a special hability,when they are in time of fecondity, they can have babies with men sheep.  
    <img src="/src/media/sheep_femme_amoureuse.bmp" >  

* You can control the shepherd with the q, d, z, s keys.  
<img src="/src/media/Berger.bmp" >  
    

* The shepherd dogs move circles around the shepherd, you can control them by left clicking on the screen to select one of them and right clicking in the screen to move them to the selected position.  
<img src="/src/media/dog.bmp" >  
    
  
The game ends when keep 1 sheeps alives or when the wolves are all dead.
