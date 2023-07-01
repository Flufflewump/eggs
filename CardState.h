#pragma once
#include "GameState.h"

class CardState : public GameState
{
public:
	CardState(SDL_Renderer* renderer);
	~CardState();

	void handleInput();
	void update(Uint64 frameTime);

private:
	Texture cardTexture;
	Texture cardImageTexture;

	void showCard(CardType type);

	int getImageOffsetX(CardType type);
	int getImageOffsetY(CardType type);
	int getMultiplier(CardType type);
};

