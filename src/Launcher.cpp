//
// Created by aroldan
//

#include "Launcher.h"
#include "Defs.h"

Launcher::Launcher() :
    font(nullptr)
{
}

Launcher::~Launcher(){
    release();
}

void Launcher::init() {
    font = TTF_OpenFont("../data/Roboto-Regular.ttf", 32);
    backgroundImage.load("../data/background.png");
    menuImage.load("../data/menu.png");
}

void Launcher::release() {
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }

    backgroundImage.release();
    menuImage.release();
}

void Launcher::render(SDL_Renderer *renderer) {
    backgroundImage.render(0, 0, renderer);
    menuImage.render(UI_MENU_LEFT, UI_MENU_TOP, UI_MENU_WIDTH, UI_MENU_HEIGHT, renderer);
}