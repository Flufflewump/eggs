#include "Window.h"

Window::Window()
{
    init();
}

bool Window::loadImage(const char* path)
{
    bool success = true;

    displayImage = SDL_LoadBMP(path);

    if (displayImage == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
        success = false;
    }

    return success;
}

void Window::showImage()
{
    SDL_BlitSurface(displayImage, NULL, windowSurface, NULL);
    SDL_UpdateWindowSurface(window);
}

void Window::close()
{
    SDL_FreeSurface(displayImage);
    displayImage = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}

bool Window::init()
{
	bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            windowSurface = SDL_GetWindowSurface(window);
        }
    }

    return success;

	return false;
}
