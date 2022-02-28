#include "System.h"

System* System::ptr = nullptr;

System* System::GetPtr()
{
    if (ptr == nullptr)
    {
        ptr = new System();
    }
    return ptr;
}

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


void System::Input()
{
    const Uint8* keyboard = SDL_GetKeyboardState(NULL);
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {

    }

}
void System::Update() 
{

}

void System::RenderClear()
{
    SDL_SetRenderDrawColor(lienzo, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(lienzo);
}

void System::Draw()
{
    SDL_RenderPresent(lienzo);
}

void System::RenderTexture(Image *img,int x,int y)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = img->GetWidth();
    dst.h = img->GetHeight();
    SDL_RenderCopy(lienzo, img->GetTexture(),NULL, &dst);
}