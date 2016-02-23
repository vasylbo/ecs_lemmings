//
// Created by Vasyl.
//

#include "ButtonSystem.h"
#include "../components/InteractiveC.h"

void ButtonSystem::configure(entityx::EntityManager &entities,
                             entityx::EventManager &events) {
    _events = &events;
    _events->subscribe<entityx::ComponentAddedEvent<ButtonC>>(*this);
    _events->subscribe<entityx::ComponentRemovedEvent<ButtonC>>(*this);
}

void onButtonClick(entityx::Entity entity, entityx::EventManager &events) {
    printf("button clicked\n");
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
}

void ButtonSystem::update(entityx::EntityManager &entities,
                          entityx::EventManager &events,
                          entityx::TimeDelta dt) {

}
