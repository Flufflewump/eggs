#include <stdio.h>
#include <SDL.h>

#include "GameState.h"
#include "MenuState.h"
#include "CardState.h"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
	}

	Window window;

	MenuState menuState(window.getRenderer());
	CardState cardState(window.getRenderer());

	//GameState* currentState = &menuState;
	GameState* currentState = &cardState;

	Uint64 frameStart, frameTime = 0;

	while (!currentState->quit) {
		frameStart = SDL_GetTicks64();
		currentState->handleInput();
		currentState->update(frameTime);

		currentState->render();

		window.update();

		if (currentState->getNextState() != GameState::State::None) {

		}

		if (SDL_GetTicks64() - frameStart < TICKS_PER_FRAME) {
			SDL_Delay(SDL_GetTicks64() - frameStart);
		}
		frameTime = SDL_GetTicks64() - frameStart;
	}


	window.close();

	return 0;
}
