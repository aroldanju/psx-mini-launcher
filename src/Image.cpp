//
// Created by aroldan
//

#include "Image.h"

Image::Image() :
    surface(nullptr),
    texture(nullptr)
{
}

Image::~Image()
{
    release();
}

void Image::release() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    if (surface) {
        SDL_FreeSurface(this->surface);
        this->surface = nullptr;
    }
}

bool Image::load(const std::string &filename) {
    release();
    this->surface = IMG_Load(filename.c_str());
    return (this->surface != nullptr);
}

void Image::render(int x, int y, SDL_Renderer *renderer) {
    if (surface) {
        render(x, y, surface->w, surface->h, renderer);
    }
}


void Image::render(int x, int y, int w, int h, SDL_Renderer *renderer) {
    if (!texture && surface) {
        this->texture = SDL_CreateTextureFromSurface(renderer, this->surface);
    }

    if (texture && surface) {
        SDL_Rect rect = (SDL_Rect){ x, y, w, h };
        SDL_RenderCopy(renderer, this->texture, nullptr, &rect);
    }
}
