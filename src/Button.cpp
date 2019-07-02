//
// Created by aroldan
//

#include "Button.h"

Button::Button(TTF_Font* font, Button_t button, const std::string &caption) {
    std::string buttonFilename = "../data/buttonCross.png";

    switch (button) {
        case BUTTON_CIRCLE: buttonFilename = "buttonCircle.png"; break;
        case BUTTON_SQUARE: buttonFilename = "buttonSquare.png"; break;
        case BUTTON_TRIANGLE: buttonFilename = "buttonTriangle.png"; break;
        case BUTTON_CROSS: buttonFilename = "buttonCross.png"; break;
    }

    this->button.load("../data/" + buttonFilename);
    this->label.setColor((SDL_Color){92, 92, 92});
    this->label.setFont(font);
    this->label.setCaption(caption);
}

Button::~Button() {
    button.release();
    label.release();
}

void Button::render(SDL_Renderer* renderer, int x, int y)   {
    int w = 20 + UI_BUTTON_SIZE + 20 + label.getWidth();
    button.render(x + 20, y, renderer);
    label.render(x + 20 + UI_BUTTON_SIZE + 20, y - 2, renderer);
}