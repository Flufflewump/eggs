#include <SDL.h>
#include <stdio.h>

#include "Window.h"

int main(int argc, char* args[])
{

	Window window;

	window.loadImage("img.bmp");
	window.showImage();

	//Hack to get window to stay up
	SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }

	window.close();

	return 0;
}
