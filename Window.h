#pragma once
#include <stdio.h>
#include <string>
#include <SDL.h>

class Window
{
public: 
	Window();
	bool loadImage(const char * path);
	void showImage();
	void close();

private:
	bool init();

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Window* window = NULL;
	SDL_Surface* windowSurface = NULL;
	SDL_Surface* displayImage = NULL;
};

