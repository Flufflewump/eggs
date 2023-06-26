#include "MenuState.h"

MenuState::MenuState(SDL_Renderer* renderer) : GameState(renderer), playTexture(renderer), exitTexture(renderer)
{
    playTexture.loadFromFile("data/PlayButtonBase.png");
    exitTexture.loadFromFile("data/ExitButtonBase.png");

    Entity* playButton = new Entity;
    playButton->addPosition(200, 200);
    playButton->addSprite(&playTexture, 0, 0, 300, 75);

    playButton->addClickable(ClickAction::Play);
    
    Entity* exitButton = new Entity;
    exitButton->addPosition(200, 400);
    exitButton->addSprite(&exitTexture, 0, 0, 300, 75);
    exitButton->addClickable(ClickAction::Exit);


    entityList.push_back(playButton);
    entityList.push_back(exitButton);
}

MenuState::~MenuState()
{
    playTexture.free();
    exitTexture.free();
}

void MenuState::handleInput()
{
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
        else if (e.type == SDL_MOUSEBUTTONUP) {

            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            PositionComponent* curPosition = NULL;
            SpriteComponent* curSprite = NULL;
            ClickableComponent* curClickable = NULL;

            for (Entity* entity : entityList) {
                curClickable = static_cast<ClickableComponent*>(entity->getComponent(ComponentType::Clickable));
                if (curClickable != NULL) {
                    curPosition = static_cast<PositionComponent*>(entity->getComponent(ComponentType::Position));
                    curSprite = static_cast<SpriteComponent*>(entity->getComponent(ComponentType::Sprite));
                    
                    // Check if click is in bounds of the entity
                    if (mouseX > curPosition->x + curSprite->offsetX && mouseY > curPosition->y + curSprite->offsetY
                        && mouseX < curPosition->x + curSprite->offsetX + curSprite->width && mouseY < curPosition->y + curSprite->offsetY + curSprite->height) {
                        switch (curClickable->action) {
                        case ClickAction::Exit:
                            quit = true;
                            break;
                        case ClickAction::Play:
                            printf("Play button pressed\n");
                            break;
                        }
                    }
                }
            }
        }
    }
}

void MenuState::update()
{
    
}
