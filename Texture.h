#pragma once

#include "CommonResources.h"
#include <SDL_image.h>

#include "Window.h"

class Texture
{
public:
	Texture(SDL_Renderer* renderer);
	~Texture();

	bool loadFromFile(std::string path);

	void free();

	void render(int x, int y, int clipX, int clipY, int clipW, int clipH, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	int getWidth();
	int getHeight();

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	int width;
	int height;
};

