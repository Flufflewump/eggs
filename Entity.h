#pragma once

#include "CommonResources.h"

#include "Component.h"

class Entity
{
public:
	Entity();
	~Entity();

	Component* getComponent(ComponentType type);

	void addPosition(int x, int y);
	void addSprite(Texture* texture, int offsetX, int offsetY, int width, int height);
	void addSprite(Texture* texture, int offsetX, int offsetY, int width, int height, int clipX, int clipY, int clipW, int clipH);
	void addClickable(ClickAction action);
	
	std::vector<Component*> components;
};

