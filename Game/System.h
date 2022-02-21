#pragma once
#include "SDL.h"
#include <iostream>
#include "Image.h"

class System
{
private:
    SDL_Window* window;
    

public: 
    void InitScreen();
    void Input();
    void Update();
    void Draw();
    void RenderTexture(Image *img,int x,int y);
    SDL_Renderer* lienzo;
};

