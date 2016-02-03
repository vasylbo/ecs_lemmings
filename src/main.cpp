#include "windows.h"
#include "SDL2/SDL.h"
#include "Game.h"

using namespace std;
namespace ex = entityx;

int main(int, char**){
	AllocConsole();
    freopen("CON", "w", stdout);

	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window *g_pWindow = SDL_CreateWindow("Lemmins",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480, SDL_WINDOW_SHOWN);
	if(g_pWindow == 0) {
        // cant create window, do smth
	}

    SDL_Renderer *g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

	Game* game = new Game(g_pRenderer);

    int start = SDL_GetTicks();
    int end;
    double dt;
	while (game->isActive()) {
        game->update(dt);
        SDL_Delay(15);

        end = SDL_GetTicks();
		dt = (end - start) / 1000.0;
		start = end;
	}

	SDL_Quit();
	return 0;
}