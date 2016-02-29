//
// Created by Vasyl.
//

#include "ButtonSystem.h"
#include "../components/InteractiveC.h"
#include "../components/RenderC.h"
#include "../components/GameC.h"

void ButtonSystem::configure(entityx::EntityManager &entities,
                             entityx::EventManager &events) {
    _events = &events;
    _entities = &entities;
    _events->subscribe<entityx::ComponentAddedEvent<ButtonC>>(*this);
    _events->subscribe<entityx::ComponentRemovedEvent<ButtonC>>(*this);
}

inline void select(ButtonC *pButtonC, entityx::Entity &pEntity) {
    RenderC *renderC = pEntity.component<RenderC>().get();
    SDL_SetTextureColorMod(renderC->texture, 255, 0, 0);
    pButtonC->state = ButtonState::SELECTED;
}

inline void deSelect(ButtonC *pButtonC, entityx::Entity &pEntity) {
    RenderC *renderC = pEntity.component<RenderC>().get();
    SDL_SetTextureColorMod(renderC->texture, 255, 255, 255);
    pButtonC->state = ButtonState::IDLE;
}

void onButtonClick(
        entityx::Entity entity,
        entityx::EntityManager &entities,
        entityx::EventManager &events) {
    GameC *gameC = (*entities.entities_with_components<GameC>().begin())
            .component<GameC>().get();

    ButtonC *clickedButton = entity.component<ButtonC>().get();

    if (clickedButton->state == ButtonState::IDLE) {
        if (gameC->selectedButton) {
            entityx::Entity selectedButton = gameC->selectedButton;
            ButtonC *sbC = selectedButton.component<ButtonC>().get();
            deSelect(sbC, selectedButton);
        }

        select(clickedButton, entity);
        gameC->selectedButton = entity;
    } else {
        deSelect(clickedButton, entity);
    }
}

void ButtonSystem::receive(const entityx::ComponentAddedEvent<ButtonC> &event) {
    auto entity = event.entity;
    entity.assign<InteractiveC>(&onButtonClick);
}

void ButtonSystem::receive(const entityx::ComponentRemovedEvent<ButtonC> &event) {
    auto entity = event.entity;
    if (entity.has_component<InteractiveC>()) {
        entity.remove<InteractiveC>();
    }
}

ButtonSystem::~ButtonSystem() {
    _events->unsubscribe<entityx::ComponentAddedEvent<ButtonC>>(*this);
    _events->unsubscribe<entityx::ComponentRemovedEvent<ButtonC>>(*this);
    _events = NULL;
    _entities = NULL;
}

void ButtonSystem::update(entityx::EntityManager &entities,
                          entityx::EventManager &events,
                          entityx::TimeDelta dt) {
    // nothing to do here
}
