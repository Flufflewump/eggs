#include "Window.h"

Window::Window()
{

    sdlWindow = SDL_CreateWindow("Untitled Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (sdlWindow == NULL)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    }
    else
    {
        //Create renderer for window
        renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == NULL)
        {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            //Initialize renderer color
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags))
            {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            }
        }
    }
}

Window::~Window()
{
    close();
}

void Window::update()
{
     SDL_RenderPresent(renderer);
}

void Window::close()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(sdlWindow);
    sdlWindow = NULL;

    IMG_Quit();
    SDL_Quit();
}

SDL_Renderer* Window::getRenderer()
{
    return renderer;
}
