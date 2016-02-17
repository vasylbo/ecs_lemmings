//
// Created by Vasyl.
//

#ifndef LEMMINGS_CONSTANTS_H
#define LEMMINGS_CONSTANTS_H

namespace constants {
    static const int APP_WIDTH = 640;
    static const int APP_HEIGHT = 400;

    static const int GAME_WIDTH = 640;
    static const int GAME_HEIGHT = 320;

    // layers
    static constexpr int GAME_LAYER = 0;
    static constexpr int GUI_LAYER = 1;

    static const int MAP_SCALE = 2;

    // map scroll
    static const int SCROLL_GAP = 20;
    static const int SCROLL_SPEED = 50;

    // lemmings spawn
    static const int DEFAULT_SPAWN_INTERVAL = 2500;

    // lemmings
    static const int MAP_STEP_HEIGHT = 5;
    static const int SIGHT = 5;
    static const int WALK_SPEED = 15;
    static const int DIG_INTERVAL = 600;
    static const int DIG_DEPTH = 4;
}

#endif //LEMMINGS_CONSTANTS_H
