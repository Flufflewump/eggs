#include "Entity.h"

Entity::Entity()
{
	
}

Entity::~Entity()
{
	for (Component* curComponent : components) {
		delete curComponent;
	}
}


Component* Entity::getComponent(ComponentType type)
{
	for (Component* component : components) {
		if (component->type == type) {
			return component;
		}
	}

	return NULL;
}

void Entity::addPosition(int x, int y, int width, int height)
{
	if (getComponent(ComponentType::Position) != NULL) {
		printf("Tried to add Position when one already exists");
		return;
	}

	PositionComponent* newComponent = new PositionComponent;
	newComponent->type = ComponentType::Position;
	newComponent->x = x;
	newComponent->y = y;
	newComponent->width = width;
	newComponent->height = height;

	components.push_back(newComponent);
}

void Entity::addSprite(Texture* texture, int offsetX, int offsetY, int width, int height)
{
	addSprite(texture, offsetX, offsetY, width, height, 0, 0, width, height);
}

void Entity::addSprite(Texture* texture, int offsetX, int offsetY, int width, int height, int clipX, int clipY, int clipW, int clipH)
{
	if (getComponent(ComponentType::Position) == NULL) {
		printf("Failed to add Sprite");
		return;
	}


	SpriteComponent* newComponent = static_cast<SpriteComponent*>(getComponent(ComponentType::Sprite));

	if (newComponent == NULL) {
		newComponent = new SpriteComponent;
		newComponent->type = ComponentType::Sprite;
		components.push_back(newComponent);
	}

	newComponent->textures.push_back(texture);
	newComponent->offsetX.push_back(offsetX);
	newComponent->offsetY.push_back(offsetY);
	newComponent->width.push_back(width);
	newComponent->height.push_back(height);
	newComponent->clipX.push_back(clipX);
	newComponent->clipY.push_back(clipY);
	newComponent->clipW.push_back(clipW);
	newComponent->clipH.push_back(clipH);
}

void Entity::addClickable(ClickAction action)
{
	if (getComponent(ComponentType::Sprite) == NULL || getComponent(ComponentType::Clickable) != NULL) {
		printf("Failed to add Clickable");
		return;
	}

	ClickableComponent* newComponent = new ClickableComponent;
	newComponent->type = ComponentType::Clickable;
	newComponent->action = action;
	newComponent->clicked = false;

	components.push_back(newComponent);
}

void Entity::addCard(CardType type)
{
	if (getComponent(ComponentType::Card) != NULL) {
		printf("Failed to add Card");
		return;
	}

	CardComponent* newComponent = new CardComponent;
	newComponent->type = ComponentType::Card;
	newComponent->cardType = type;
	newComponent->onCursor = false;

	components.push_back(newComponent);
}
