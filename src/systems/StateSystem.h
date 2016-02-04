//
// Created by Vasyl.
//

#ifndef LEMMINGS_STATESYSTEM_H
#define LEMMINGS_STATESYSTEM_H


#include <entityx/System.h>
#include "../components/GroundedC.h"

class StateSystem : public entityx::System<StateSystem>,
                    public entityx::Receiver<StateSystem> {
public:
    StateSystem() {};


    virtual void configure(entityx::EntityManager &entities,
                           entityx::EventManager &events) override;

    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;

    void receive(const entityx::ComponentAddedEvent<GroundedC> &event);
    void receive(const entityx::ComponentRemovedEvent<GroundedC> &event);
};


#endif //LEMMINGS_STATESYSTEM_H
