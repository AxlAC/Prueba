#include "System.h"

void System::InitScreen()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error video";
    }
    else
    {
        window = SDL_CreateWindow("Buscaminas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 640, SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            std::cout<<"No se pudo cargar ventana";
        }
        else
        {
            lienzo = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (lienzo == nullptr)
            {
                std::cout<<"No se pudo crear el lienzo";
            }
            else
            {
                SDL_SetRenderDrawColor(lienzo,255,0,0,255);
            }
        }
    }
}