#include "Image.h"

SDL_Texture* Image::GetTexture()
{
	return image;
}

void Image::Load(SDL_Renderer* lienzo, const std::string name)
{
	SDL_Surface* loadSurface = IMG_Load(name.c_str());
	image = SDL_CreateTextureFromSurface(lienzo, loadSurface);
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
