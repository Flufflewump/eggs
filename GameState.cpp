#include "GameState.h"

GameState::GameState(SDL_Renderer* renderer) : quit(false), renderer(renderer), nextState(GameState::State::None)
{
}

GameState::~GameState()
{
	for (Entity* curEntity : entityList) {
		delete curEntity;
	}
}

void GameState::update(Uint64 frameTime)
{
}

void GameState::render()
{
	SDL_RenderClear(renderer);

	SpriteComponent* curSprite = NULL;
	PositionComponent* curPosition = NULL;

	for (Entity* entity : entityList) {
		curSprite = static_cast<SpriteComponent*>(entity->getComponent(ComponentType::Sprite));
		if (curSprite != NULL) {
			curPosition = static_cast<PositionComponent*>(entity->getComponent(ComponentType::Position));
			for (int i = 0; i < curSprite->textures.size(); i++) {
				Texture* curTexture = curSprite->textures[i];
				curTexture->render(curPosition->x + curSprite->offsetX[i], curPosition->y + curSprite->offsetY[i],
									curSprite->clipX[i], curSprite->clipY[i], curSprite->clipW[i], curSprite->clipH[i]);
			}
		}
	}
}

void GameState::enter()
{
}

void GameState::leave()
{
}

GameState::State GameState::getNextState()
{
	return nextState;
}
