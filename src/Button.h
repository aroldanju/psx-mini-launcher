//
// Created by aroldan
//

#ifndef __Button_h__
#define __Button_h__

#include <string>
#include "Defs.h"
#include "Label.h"
#include "Image.h"

class Button {
public:
    Button(TTF_Font* font, Button_t button, const std::string& caption);
    virtual ~Button();

    void render(SDL_Renderer* renderer, int x, int y);

private:
    Image button;
    Label label;
};


#endif // __Button_h__
