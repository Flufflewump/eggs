#include "CardState.h"

CardState::CardState(SDL_Renderer* renderer) : GameState(renderer), cardTexture(renderer), cardImageTexture(renderer)
{
	cardTexture.loadFromFile("data/CardBase.png");
	cardImageTexture.loadFromFile("data/CardImages.png");

	showCard(CardType::Attack);

}

CardState::~CardState()
{
	cardTexture.free();
	cardImageTexture.free();
}

void CardState::handleInput()
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		else if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_a) {
				showCard(CardType::Attack);
			}
			else if (e.key.keysym.sym == SDLK_d) {
				showCard(CardType::Defend);
			}
			else if (e.key.keysym.sym == SDLK_h) {
				showCard(CardType::Heal);
			}
		}
	}
}

void CardState::update(Uint64 frameTime)
{
	for (auto* curEntity : entityList) {

		// Move all the cards
		
		if (curEntity->getComponent(ComponentType::Card)) {
			static_cast<PositionComponent*>(curEntity->getComponent(ComponentType::Position))->x -= CARD_MOVE_SPEED * frameTime / 1000;
		}
	}
}

void CardState::showCard(CardType type)
{
	Entity* newCard = new Entity();

	newCard->addPosition(CARD_STARTX, CARD_STARTY, CARD_WIDTH, CARD_HEIGHT);
	newCard->addSprite(&cardImageTexture, CARD_IMAGE_OFFSETX, CARD_IMAGE_OFFSETY, CARD_IMAGE_WIDTH, CARD_IMAGE_HEIGHT,
						getImageOffsetX(type), getImageOffsetY(type), CARD_IMAGE_WIDTH, CARD_IMAGE_HEIGHT);
	newCard->addSprite(&cardTexture, 0, 0, CARD_WIDTH, CARD_HEIGHT);
	newCard->addClickable(ClickAction::Card);
	newCard->addCard(type);
	
	entityList.push_back(newCard);
}

int CardState::getImageOffsetX(CardType type)
{
	return getMultiplier(type) % CARD_TEXTURE_COLUMNS * CARD_IMAGE_WIDTH;
}

int CardState::getImageOffsetY(CardType type)
{
	return floor(getMultiplier(type) / CARD_TEXTURE_COLUMNS * CARD_IMAGE_HEIGHT);
}

int CardState::getMultiplier(CardType type)
{
	switch (type) {
	case CardType::Attack:
		return 0;
		break;
	case CardType::Defend:
		return 1;
		break;
	case CardType::Heal:
		return 2;
		break;
	}
}


