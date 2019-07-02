//
// Created by aroldan
//

#include <tinyxml2.h>
#include <iostream>
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
    selectionImage.load("../data/selection.png");

    loadGames();

    buttonSelectGame = new Button(font, BUTTON_CROSS, "Select game");
}

void Launcher::release() {
    if (buttonSelectGame) {
        delete buttonSelectGame;
        buttonSelectGame = nullptr;
    }

    for (auto& game : games) {
        delete game;
    }
    games.erase(games.begin(), games.end());

    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }

    selectionImage.release();
    backgroundImage.release();
    menuImage.release();
}

void Launcher::render(SDL_Renderer *renderer) {
    backgroundImage.render(0, 0, renderer);
    selectionImage.render(810, 235, renderer);
    menuImage.render(UI_MENU_LEFT, UI_MENU_TOP, UI_MENU_WIDTH, UI_MENU_HEIGHT, renderer);

    buttonSelectGame->render(renderer, SCREEN_WIDTH / 2, UI_MENU_TOP + 20);
}

bool Launcher::loadGames() {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError error;
    tinyxml2::XMLElement *root, *nodeGame, *node;
    const char *stringAttribute;
    uint32_t players, released;
    std::string cover, image, name;

    const std::string filename = "../data/games.xml";

    error = doc.LoadFile(filename.c_str());
    if (error != tinyxml2::XML_SUCCESS) 	{
        return false;
    }

    root = doc.FirstChildElement("games");
    if (!root) {
        return false;
    }

    nodeGame = root->FirstChildElement("game");
    while (nodeGame)	{
        if ( !(stringAttribute = nodeGame->Attribute("name")) ) {
            return false;
        }

        name = std::string(stringAttribute);

        if ((node = nodeGame->FirstChildElement("released"))) {
            stringAttribute = node->GetText();
            released = (uint32_t)std::atoi(stringAttribute);
        }

        if ((node = nodeGame->FirstChildElement("players"))) {
            stringAttribute = node->GetText();
            players = (uint32_t)std::atoi(stringAttribute);
        }

        if ((node = nodeGame->FirstChildElement("cover"))) {
            stringAttribute = node->GetText();
            cover = std::string(stringAttribute);
        }

        if ((node = nodeGame->FirstChildElement("image"))) {
            stringAttribute = node->GetText();
            image = std::string(stringAttribute);
        }

        this->games.push_back(new Game(name, released, players, cover, image));

        nodeGame = nodeGame->NextSiblingElement();
    }

#ifdef __DEBUG__
    std::cout << this->games.size() << " game(s) loaded." << std::endl;
#endif

    return true;
}

void Launcher::runGame() {
}