#pragma once
#include "CommonResources.h"
#include "Texture.h"

enum class ComponentType {
	Position,
	Sprite,
	Clickable,
	Card
};

enum class ClickAction {
	Exit,
	Play,
	Card
};

enum class CardType {
	Attack,
	Defend,
	Heal
};

struct Component {
	ComponentType type;
};

struct PositionComponent : public Component {
	int x, y, width, height;
};

struct SpriteComponent : public Component {
	std::vector<Texture*> textures;
	std::vector<int> offsetX, offsetY, width, height;
	std::vector<int> clipX, clipY, clipW, clipH;
};

struct ClickableComponent : public Component {
	ClickAction action;
	bool clicked;
};

struct CardComponent : public Component {
	CardType cardType;
	bool onCursor;
};