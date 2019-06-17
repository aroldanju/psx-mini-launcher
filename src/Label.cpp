//
// Created by aroldan
//

#include "Label.h"

Label::Label() :
    surface(nullptr),
    texture(nullptr),
    color((SDL_Color){255, 255, 255})
{
}

Label::~Label() {
    release();
}

void Label::setCaption(const std::string& caption)  {
    if (this->caption != caption) {
        this->caption = caption;
        release();
        this->surface = TTF_RenderText_Blended(this->font, this->caption.c_str(), this->color);
    }
}

void Label::setColor(const SDL_Color& color)   {
    this->color = color;
}

void Label::setFont(TTF_Font* font) {
    this->font = font;
}

void Label::release() {
    if (surface) {
        SDL_FreeSurface(surface);
        surface = nullptr;
    }

    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

void Label::render(int x, int y, SDL_Renderer* renderer)   {
    if (!texture && surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
    }

    if (texture && surface) {
        SDL_Rect rect = (SDL_Rect){ x, y, surface->w, surface->h };
        SDL_RenderCopy(renderer, texture, nullptr, &rect);
    }
}
