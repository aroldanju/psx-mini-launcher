//
// Created by aroldan
//

#include "Game.h"

Game::Game()
    : released(0), players(0),
      cover(""),
      image(""), name("")
{
}

Game::Game(const std::string& name, uint32_t released, uint8_t players, const std::string& cover, const std::string& image)
    : released(released), players(players),
      cover(cover),
      image(image), name(name)
{
    create();
}

Game::~Game() {
    coverImage.release();
}

uint32_t Game::getReleased() const {
    return released;
}

void Game::setReleased(uint32_t released) {
    Game::released = released;
}

const std::string& Game::getName() const  {
    return this->name;
}

void Game::setName(const std::string& name) {
    this->name = name;
}

uint8_t Game::getPlayers() const {
    return players;
}

void Game::setPlayers(uint8_t players) {
    Game::players = players;
}

Image& Game::getCoverImage() {
    return coverImage;
}

const std::string &Game::getImage() const {
    return image;
}

void Game::setImage(const std::string &image) {
    Game::image = image;
}

bool Game::create() {
    return this->coverImage.load(cover);
}