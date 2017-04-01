//
// Created by Vasyl.
//

#ifndef LEMMINGS_BUTTONSYSTEM_H
#define LEMMINGS_BUTTONSYSTEM_H


#include <entityx/System.h>
#include "../components/StateSwitchButtonC.h"

class StateSwitchButtonSystem :
        public entityx::System<StateSwitchButtonSystem>,
        public entityx::Receiver<StateSwitchButtonSystem> {
public:
    StateSwitchButtonSystem(){};
    virtual void configure(entityx::EntityManager &entities,
                           entityx::EventManager &events) override;

    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;

    virtual ~StateSwitchButtonSystem();

private:
    entityx::EventManager *_events;
    entityx::EntityManager *_entities;
};


#endif //LEMMINGS_BUTTONSYSTEM_H
