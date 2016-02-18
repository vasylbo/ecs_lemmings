//
// Created by Vasyl.
//

#include "ButtonSystem.h"

void ButtonSystem::configure(entityx::EntityManager &entities,
                             entityx::EventManager &events) {
    _events = &events;
    _events->subscribe<entityx::ComponentAddedEvent<ButtonC>>(*this);
    _events->subscribe<entityx::ComponentRemovedEvent<ButtonC>>(*this);
}

void ButtonSystem::receive(const entityx::ComponentAddedEvent<ButtonC> &event) {

}

void ButtonSystem::receive(const entityx::ComponentRemovedEvent<ButtonC> &event) {

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
