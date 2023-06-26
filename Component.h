#pragma once
#include "CommonResources.h"
#include "Texture.h"

enum class ComponentType {
	Position,
	Sprite,
	Clickable
};

enum class ClickAction {
	Exit,
	Play
};

struct Component {
	ComponentType type;
};

struct PositionComponent : public Component {
	int x, y;
};

struct SpriteComponent : public Component {
	Texture* texture;
	int offsetX, offsetY, width, height;
	int clipX, clipY, clipW, clipH;
};

struct ClickableComponent : public Component {
	ClickAction action;
	bool clicked;
};