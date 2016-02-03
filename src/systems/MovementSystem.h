//
// Created by Vasyl.
//

#ifndef LEMMINGS_MOVEMENTSYSTEM_H
#define LEMMINGS_MOVEMENTSYSTEM_H


#include <entityx/System.h>

class MovementSystem : public entityx::System<MovementSystem> {
public:
    MovementSystem();
    virtual void update(entityx::EntityManager &entities, entityx::EventManager &events,
                        entityx::TimeDelta dt) override;
};


#endif //LEMMINGS_MOVEMENTSYSTEM_H
