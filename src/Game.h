//
// Created by Vasyl.
//
#pragma once

#include "SDL_render.h"
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
#include "components/AssetC.h"
#include "systems/AnimationSystem.h"
#include "components/AnimationC.h"
#include "systems/StateSystem.h"

namespace ex = entityx;

class Game {
public:
    //    move implementation to *.cpp
    explicit Game(SDL_Renderer *pRenderer) :
            _events(),
            _entities(_events),
            _systems(_entities, _events) {
        _systems.add<AnimationSystem>();
        _systems.add<MoveSensorSystem>();
        _systems.add<MovementSystem>();
        _systems.add<PhysicsSystem>();
        _systems.add<RenderSystem>(pRenderer);
        _systems.add<StateSystem>();
        _systems.configure();

        createBack(pRenderer);
        createLemming(pRenderer);
    }

    void createBack(SDL_Renderer *pRenderer) {
        ex::Entity back = _entities.create();

        SDL_Surface *surface = SDL_LoadBMP("level.bmp");

        back.assign<AssetC>("level.bmp");
        back.assign<SurfaceC>(surface, 5);
        back.assign<PositionC>(0, 0);
    }

    void createLemming(SDL_Renderer *pRenderer) {
        ex::Entity lemming = _entities.create();

        lemming.assign<AssetC>("lemming.bmp");
        lemming.assign<AnimationC>("idle", 15);
        lemming.assign<LemmingC>();
        lemming.assign<SensorC>(5, 5);
        lemming.assign<MoveC>(9);
        lemming.assign<PhysicsC>();
        lemming.assign<PositionC>(180, 60);
    }

    void update(ex::TimeDelta dt) {
        _systems.update_all(dt);
    };

    bool isActive() {
        return true;
    };

    ~Game() {
    };
private:
    ex::EntityManager _entities;
    ex::SystemManager _systems;
    ex::EventManager _events;
};


