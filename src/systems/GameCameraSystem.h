//
// Created by Vasyl.
//

#ifndef LEMMINGS_SCROLLSYSTEM_H
#define LEMMINGS_SCROLLSYSTEM_H


#include <entityx/System.h>

class GameCameraSystem : public entityx::System<GameCameraSystem> {
public:
    GameCameraSystem() {};

    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;
};


#endif //LEMMINGS_SCROLLSYSTEM_H
