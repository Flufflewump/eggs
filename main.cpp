#include <stdio.h>
#include <SDL.h>

#include "GameState.h"
#include "MenuState.h"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
	}

	Window window;

	MenuState menuState(window.getRenderer());

	GameState* currentState = &menuState;

	while (!currentState->quit) {
		currentState->handleInput();
		currentState->update();
		currentState->render();
		window.update();

		if (currentState->getNextState() != GameState::State::None) {

		}
	}


	window.close();

	return 0;
}
