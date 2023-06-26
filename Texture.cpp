#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer) : texture(NULL), renderer(renderer), width(0), height(0)
{

}

Texture::~Texture()
{
	free();
}

bool Texture::loadFromFile(std::string path)
{
	bool success = true;

	free();

	texture = IMG_LoadTexture(renderer, path.c_str());

	if (texture == NULL) {
		printf("Texture could not be loaded!\nPath: %s\nSDL Error: %s\n", path.c_str(), SDL_GetError());
		success = false;
	}

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);


	return success;
}

void Texture::free()
{
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

void Texture::render(int x, int y, int clipX, int clipY, int clipW, int clipH,  double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, width, height };


	renderQuad.w = clipW;
	renderQuad.h = clipH;


	SDL_Rect clipQuad = { clipX, clipY, clipW, clipH };

	SDL_RenderCopyEx(renderer, texture, &clipQuad, &renderQuad, angle, center, flip);

}

int Texture::getWidth()
{
	return width;
}

int Texture::getHeight()
{
	return height;
}
