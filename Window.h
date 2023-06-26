#pragma once
#include "CommonResources.h"

#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Window
{
public: 
	Window();
	~Window();

	void update();
	void close();

	SDL_Renderer* getRenderer();

private:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Window* sdlWindow = NULL;
	SDL_Renderer* renderer = NULL;
};

