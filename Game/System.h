#pragma once
#include "SDL.h"
#include <iostream>
#include "Image.h"


class System
{
private:
    SDL_Window* window;
    System() {};
    static System* ptr;
public: 
    static System* GetPtr();
    void InitScreen();
    void Input();
    void Update();
    void Draw();
    void RenderTexture(Image *img,int x,int y);
    void RenderClear();
    SDL_Renderer* lienzo;
};

