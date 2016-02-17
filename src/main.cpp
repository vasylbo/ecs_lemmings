#include "windows.h"
#include "SDL.h"
#include "Game.h"
#include "Constants.h"

using namespace std;
namespace ex = entityx;

void showRendererInfo(SDL_Renderer *pRenderer) {
    SDL_RendererInfo rendererInfo = SDL_RendererInfo();
    SDL_GetRendererInfo(pRenderer, &rendererInfo);

    printf("Renderer type %s \n", rendererInfo.name);
}

void loop(Game *pGame) {
    int start = SDL_GetTicks();
    int end;
    double dt;
    while (pGame->isActive()) {
        pGame->update(dt);
        SDL_Delay(15);

        end = SDL_GetTicks();
        dt = (end - start) / 1000.0;
        start = end;
    }
}

int main(int, char **) {
    AllocConsole();
    freopen("CON", "w", stdout);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s \n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
            "Lemmins",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            constants::APP_WIDTH, constants::APP_HEIGHT,
            SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    showRendererInfo(renderer);

    Game *game = new Game(renderer);
    loop(game);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
