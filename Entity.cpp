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

void Entity::addPosition(int x, int y)
{
	if (getComponent(ComponentType::Position) != NULL) {
		printf("Tried to add Position when one already exists");
		return;
	}

	PositionComponent* newComponent = new PositionComponent;
	newComponent->type = ComponentType::Position;
	newComponent->x = x;
	newComponent->y = y;

	components.push_back(newComponent);
}

void Entity::addSprite(Texture* texture, int offsetX, int offsetY, int width, int height)
{
	addSprite(texture, offsetX, offsetY, width, height, 0, 0, width, height);
}

void Entity::addSprite(Texture* texture, int offsetX, int offsetY, int width, int height, int clipX, int clipY, int clipW, int clipH)
{
	if (getComponent(ComponentType::Position) == NULL || getComponent(ComponentType::Sprite) != NULL) {
		printf("Failed to add Sprite");
		return;
	}

	SpriteComponent* newComponent = new SpriteComponent;
	newComponent->type = ComponentType::Sprite;
	newComponent->texture = texture;
	newComponent->offsetX = offsetX;
	newComponent->offsetY = offsetY;
	newComponent->width = width;
	newComponent->height = height;
	newComponent->clipX = clipX;
	newComponent->clipY = clipY;
	newComponent->clipW = clipW;
	newComponent->clipH = clipH;

	components.push_back(newComponent);
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
