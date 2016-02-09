//
// Created by Vasyl.
//

#ifndef LEMMINGS_DIGGERSYSTEM_H
#define LEMMINGS_DIGGERSYSTEM_H


#include <entityx/System.h>
#include <SDL_render.h>

class DiggerSystem : public entityx::System<DiggerSystem> {
public:
    DiggerSystem(SDL_Renderer* pRenderer): _renderer(pRenderer) {}

    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;
private:
    SDL_Renderer* _renderer;
};


#endif //LEMMINGS_DIGGERSYSTEM_H
