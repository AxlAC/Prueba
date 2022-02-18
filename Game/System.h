#pragma once
#include "SDL.h"
#include <iostream>

class System
{
private:
    SDL_Window* window;
    SDL_Renderer* lienzo;

public: 
    void InitScreen();
};

