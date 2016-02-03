//
// Created by Vasyl.
//
#pragma once

#include "SDL2/SDL_render.h"
#include "entityx/System.h"
#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "components/RenderC.h"
#include "components/PositionC.h"
#include "systems/RenderSystem.h"
#include "components/SurfaceC.h"
#include "components/LemmingC.h"
#include "systems/PhysicsSystem.h"
#include "components/PhysicsC.h"
#include "systems/MovementSystem.h"
#include "components/SensorC.h"
#include "components/MoveC.h"
#include "systems/MoveSensorSystem.h"

namespace ex = entityx;

class Game {
public:
//    move implementation to *.cpp
    explicit Game(SDL_Renderer *pRenderer) :
            _events(),
            _entities(_events),
            _systems(_entities, _events) {
        _systems.add<RenderSystem>(pRenderer);
        _systems.add<PhysicsSystem>();
        _systems.add<MovementSystem>();
        _systems.add<MoveSensorSystem>();
        _systems.configure();

        createBack(pRenderer);
        createLemming(pRenderer);
    }

    void createBack(SDL_Renderer* pRenderer) {
        ex::Entity back = _entities.create();

        SDL_Surface *surface = SDL_LoadBMP("level.bmp");
        SDL_Texture *texture = SDL_CreateTextureFromSurface(pRenderer, surface);

        back.assign<RenderC>(texture);
        back.assign<SurfaceC>(surface);
        back.assign<PositionC>(0, 0);
    }

    void createLemming(SDL_Renderer* pRenderer) {
        ex::Entity lemming = _entities.create();
        SDL_Texture *texture = toTexture("lemming.bmp", pRenderer);

        lemming.assign<RenderC>(texture);
        lemming.assign<LemmingC>();
        lemming.assign<SensorC>(5, 5);
        lemming.assign<MoveC>(1);
        lemming.assign<PhysicsC>();
        lemming.assign<PositionC>(300, 60);
    }

    SDL_Texture *toTexture(const char *pId, SDL_Renderer *pRenderer) {
        SDL_Surface *surface = SDL_LoadBMP(pId);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(pRenderer, surface);
        SDL_FreeSurface(surface);
        return texture;
    }

    void update(ex::TimeDelta dt) {
        _systems.update_all(dt);
    };

    bool isActive() {
        return true;
    };

    ~Game() { };
private:
    ex::EntityManager _entities;
    ex::SystemManager _systems;
    ex::EventManager _events;
};


