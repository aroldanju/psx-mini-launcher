//
// Created by aroldan
//

#ifndef __Launcher_h__
#define __Launcher_h__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Image.h"

class Launcher {
public:
    Launcher();
    virtual ~Launcher();

    void init();
    void release();

    void render(SDL_Renderer* renderer);

private:
    TTF_Font *font;
    Image menuImage;
    Image backgroundImage;
};


#endif // __Launcher_h__
