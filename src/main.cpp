#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Connection.h"
#include "Launcher.h"
#include "Defs.h"
#include "Label.h"

bool init(SDL_Renderer** renderer, SDL_Window** window);
void release(SDL_Renderer** renderer, SDL_Window** window);

int main() {
    std::cout << "psx-mini-launcher" << std::endl;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    bool quit = false;
    Launcher launcher;
    uint32_t ticks;

    if (!init(&renderer, &window)) {
        return 1;
    }

    launcher.init();

    ticks = SDL_GetTicks();;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_RenderClear(renderer);
        launcher.render(renderer);
        SDL_RenderPresent(renderer);

        uint32_t elapsed = SDL_GetTicks() - ticks;
        if (elapsed < 1000 / FPS) {
            SDL_Delay(1000 / FPS - elapsed);
        }
        else {
            SDL_Delay(1);
        }

        ticks = SDL_GetTicks();
    }

    launcher.release();

    release(&renderer, &window);

    return 0;
}

bool init(SDL_Renderer** renderer, SDL_Window** window) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "init: " << SDL_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() != 0) {
        std::cout << "init: " << SDL_GetError() << std::endl;
        return false;
    }

#ifdef __DEBUG__
    if (!(*window = SDL_CreateWindow("psx-mini-launcher", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SDL_WINDOW_RESIZABLE))) {
#else
    if (!(*window = SDL_CreateWindow("psx-mini-launcher", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0))) {
#endif
        std::cout << "init: " << SDL_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return false;
    }

    if (!(*renderer = SDL_CreateRenderer(*window, -1, 0))) {
        std::cout << "init: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(*window);
        TTF_Quit();
        SDL_Quit();
        return false;
    }

    SDL_RenderSetLogicalSize(*renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

    return true;
}

void release(SDL_Renderer** renderer, SDL_Window** window) {
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);

    TTF_Quit();
    SDL_Quit();
}
