#pragma once

#include "GameState.h"
#include "Settings.h"
#include "Window.h"

#include "Texture.h"

class MenuState: public GameState  {
public:
	MenuState(SDL_Renderer* renderer);
	~MenuState();

	void handleInput();
	void update();

private:
	Texture playTexture;
	Texture exitTexture;
};