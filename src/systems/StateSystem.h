//
// Created by Vasyl.
//

#ifndef LEMMINGS_STATESYSTEM_H
#define LEMMINGS_STATESYSTEM_H


#include <entityx/System.h>
#include "../components/GroundedC.h"
#include "../events/StateChangeEvent.h"
#include "../LemmingBuilder.h"

class StateSystem : public entityx::System<StateSystem>,
                    public entityx::Receiver<StateSystem> {
public:
    StateSystem(LemmingBuilder* pBuilder);

    virtual void configure(entityx::EntityManager &entities,
                           entityx::EventManager &events) override;

    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;

    void receive(const entityx::ComponentAddedEvent<GroundedC> &event);
    void receive(const entityx::ComponentRemovedEvent<GroundedC> &event);
    void receive(const StateChangeEvent &event);

private:
    void switchToDigger(entityx::Entity& entity);
    LemmingBuilder* _builder;
};


#endif //LEMMINGS_STATESYSTEM_H
