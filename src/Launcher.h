//
// Created by aroldan
//

#ifndef __Launcher_h__
#define __Launcher_h__

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Image.h"
#include "Game.h"
#include "Button.h"

class Launcher {
public:
    Launcher();
    virtual ~Launcher();

    void init();
    void release();

    void render(SDL_Renderer* renderer);

    bool loadGames();

    void runGame();

private:
    TTF_Font *font;
    Image menuImage;
    Image backgroundImage;
    Image selectionImage;

    std::vector<Game*> games;

    Button* buttonSelectGame;

};


#endif // __Launcher_h__
