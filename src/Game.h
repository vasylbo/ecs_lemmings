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
#include "systems/AnimationSystem.h"
#include "components/AssetC.h"
#include "components/GameC.h"
#include "components/AnimationC.h"
#include "systems/StateSystem.h"
#include "systems/SpawnSystem.h"

namespace ex = entityx;

class Game {
public:
    //    move implementation to *.cpp
    explicit Game(SDL_Renderer *pRenderer) :
            _events(),
            _entities(_events),
            _systems(_entities, _events) {
        _systems.add<RenderSystem>(pRenderer);
        _systems.add<AnimationSystem>();
        _systems.add<MovementSystem>();
        _systems.add<MoveSensorSystem>();
        _systems.add<PhysicsSystem>();
        _systems.add<StateSystem>();
        _systems.add<SpawnSystem>();
        _systems.configure();

        createGame();
        createBack(pRenderer);
    }

    void createGame() {
        ex::Entity game = _entities.create();

        game.assign<GameC>(40, 1500);
    }

    void createBack(SDL_Renderer *pRenderer) {
        ex::Entity back = _entities.create();

        // todo: double load
        SDL_Surface *surface = SDL_LoadBMP("level.bmp");

        back.assign<AssetC>("level.bmp");
        back.assign<SurfaceC>(surface, 5);
        back.assign<PositionC>(0, 0);
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


