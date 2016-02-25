//
// Created by Vasyl.
//

#ifndef LEMMINGS_BUTTONSYSTEM_H
#define LEMMINGS_BUTTONSYSTEM_H


#include <entityx/System.h>
#include "../components/ButtonC.h"

class ButtonSystem :
        public entityx::System<ButtonSystem>,
        public entityx::Receiver<ButtonSystem> {
public:
    ButtonSystem(){};
    virtual void configure(entityx::EntityManager &entities,
                           entityx::EventManager &events) override;

    void receive(const entityx::ComponentAddedEvent<ButtonC>&);
    void receive(const entityx::ComponentRemovedEvent<ButtonC>&);

    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;

    virtual ~ButtonSystem();

private:
    entityx::EventManager *_events;
    entityx::EntityManager *_entities;
};


#endif //LEMMINGS_BUTTONSYSTEM_H
