//
// Created by Vasyl.
//
#pragma once

#include <SDL_config_lib.h>
#include "SDL_render.h"
#include "entityx/System.h"
#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "components/RenderC.h"
#include "components/PositionC.h"
#include "systems/RenderSystem.h"
#include "components/SurfaceC.h"
#include "components/LemmingC.h"
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
#include "systems/InputSystem.h"
#include "systems/DiggerSystem.h"
#include "systems/FallSystem.h"
#include "LemmingBuilder.h"

namespace ex = entityx;

class Game {
public:
    //    move implementation to *.cpp
    explicit Game(SDL_Renderer *pRenderer) :
            _events(),
            _entities(_events),
            _systems(_entities, _events),
            _builder(&_entities){
        _systems.add<RenderSystem>(pRenderer);
        _systems.add<AnimationSystem>();
        _systems.add<MovementSystem>();
        _systems.add<MoveSensorSystem>();
        _systems.add<DiggerSystem>(pRenderer);
        _systems.add<FallSystem>();
        _systems.add<StateSystem>(&_builder);
        _systems.add<SpawnSystem>(&_builder);
        _systems.add<InputSystem>();
        _systems.configure();

//        CFG_File cfg;
//        int result = CFG_OpenFile("game.cfg", &cfg);
//        printf("file result %d \n", result);


//        cfg.SelectGroup("Game");
//        for (cfg.StartGroupIteration(); cfg.IsLastEntry(); cfg
//                .SelectNextEntry()) {
//            printf(cfg.ReadText(CFG_ENTRY_ITERATION, 0));
//        }


        createGame();
        createBack(pRenderer);
    }

    void createGame() {
        ex::Entity game = _entities.create();

        game.assign<GameC>(40, 2500);
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
    LemmingBuilder _builder;
    ex::EntityManager _entities;
    ex::SystemManager _systems;
    ex::EventManager _events;
};


