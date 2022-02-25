#include "Image.h"
#include "System.h"
SDL_Texture* Image::GetTexture()
{
	return image;
}

void Image::Load(const std::string name)
{
	System* sys = System::GetPtr();
	SDL_Surface* loadSurface = IMG_Load(name.c_str());
	image = SDL_CreateTextureFromSurface(sys->GetPtr()->lienzo, loadSurface);
	SDL_QueryTexture(image, NULL, NULL, &width, &height);
	SDL_free(loadSurface);
}

int Image::GetWidth()
{
	return width;
}

int Image::GetHeight()
{
	return height;
}
