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

void GameState::update()
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
			curSprite->texture->render(curPosition->x + curSprite->offsetX, curPosition->y + curSprite->offsetY, curSprite->clipX, curSprite->clipY, curSprite->clipW, curSprite->clipH);
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
