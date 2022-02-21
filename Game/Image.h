#pragma once
#include <string>
#include "SDL.h"
#include "SDL_image.h"

using namespace std;
class Image
{	
	private:
		SDL_Texture *image;
		int width;
		int height;
		string saveName;
	public:
		SDL_Texture *GetTexture();
		void Load(SDL_Renderer* lienzo, const std::string name);
		int GetWidth();
		int GetHeight();
		

};



