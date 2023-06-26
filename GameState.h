#pragma once

#include <SDL.h>
#include "CommonResources.h"
#include "Window.h"
#include "Entity.h"

class GameState
{
public:
	enum class State {
		None,
		MenuState,
		PlayState
	};

	GameState(SDL_Renderer* renderer);
	~GameState();

	virtual void handleInput() = 0;
	virtual void update();
	virtual void render();

	virtual void enter();
	virtual void leave();

	bool quit;

	GameState::State getNextState();

protected:
	SDL_Renderer* renderer;
	GameState::State nextState;

	std::vector<Entity*> entityList;
};

