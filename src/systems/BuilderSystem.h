//
// Created by Vasyl.
//

#ifndef LEMMINGS_BUILDERSYSTEM_H
#define LEMMINGS_BUILDERSYSTEM_H


#include <entityx/System.h>
#include <SDL_render.h>

class BuilderSystem : public entityx::System<BuilderSystem> {
public:
    BuilderSystem(SDL_Renderer *pRenderer);

    virtual void update(entityx::EntityManager &entities,
                        entityx::EventManager &events,
                        entityx::TimeDelta dt) override;

private:
    SDL_Renderer *_renderer;
};


#endif //LEMMINGS_BUILDERSYSTEM_H
