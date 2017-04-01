//
// Created by Vasyl.
//

#include "StateSwitchButtonSystem.h"
#include "../components/InteractiveC.h"
#include "../components/RenderC.h"
#include "../components/GameC.h"

void StateSwitchButtonSystem::configure(entityx::EntityManager &entities,
                             entityx::EventManager &events) {
    _events = &events;
    _entities = &entities;
    _events->subscribe<StateChangeEvent>(*this);
}

inline void select(StateSwitchButtonC *pButtonC, entityx::Entity &pEntity) {
    RenderC *renderC = pEntity.component<RenderC>().get();
    SDL_SetTextureColorMod(renderC->texture, 255, 0, 0);
    pButtonC->state = ButtonState::SELECTED;
}

inline void deSelect(StateSwitchButtonC *pButtonC, entityx::Entity &pEntity) {
    RenderC *renderC = pEntity.component<RenderC>().get();
    SDL_SetTextureColorMod(renderC->texture, 255, 255, 255);
    pButtonC->state = ButtonState::IDLE;
}

StateSwitchButtonSystem::~StateSwitchButtonSystem() {
    _events->unsubscribe<entityx::ComponentAddedEvent<StateSwitchButtonC>>(*this);
    _events->unsubscribe<entityx::ComponentRemovedEvent<StateSwitchButtonC>>(*this);
    _events = NULL;
    _entities = NULL;
}

void onButtonClick(
        entityx::Entity entity,
        entityx::EntityManager &entities,
        entityx::EventManager &events) {
    GameC *gameC = (*entities.entities_with_components<GameC>().begin())
            .component<GameC>().get();

    StateSwitchButtonC *clickedButton = entity.component<StateSwitchButtonC>().get();

    if (clickedButton->state == ButtonState::IDLE) {
        if (gameC->selectedButtonEntity) {
            entityx::Entity selectedButton = gameC->selectedButtonEntity;
            StateSwitchButtonC *sbC = selectedButton.component<StateSwitchButtonC>().get();
            deSelect(sbC, selectedButton);
        }

        select(clickedButton, entity);
        gameC->selectedButtonEntity = entity;
    } else {
        deSelect(clickedButton, entity);
    }
}

void StateSwitchButtonSystem::update(entityx::EntityManager &entities,
                          entityx::EventManager &events,
                          entityx::TimeDelta dt) {
	for (entityx::Entity entity : 
		entities.entities_with_components<InteractiveC, StateSwitchButtonC>())
	{
		if (entity.component<InteractiveC>()->hasBeenClicked) 
		{
			onButtonClick(entity, entities, events);
		}
	}
}

void StateSwitchButtonSystem::receive(const StateChangeEvent&) {
    std::cout << "receive" << std::endl;
//    _events->emit()
}
