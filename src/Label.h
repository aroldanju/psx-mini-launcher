//
// Created by aroldan
//

#ifndef __Label_h__
#define __Label_h__

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Label {
public:
    Label();
    virtual ~Label();

    void setCaption(const std::string& caption);
    void setFont(TTF_Font* font);

    void release();

    void setColor(const SDL_Color& color);

    void render(int x, int y, SDL_Renderer* renderer);

private:
    std::string caption;
    TTF_Font *font;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Color color;
};


#endif // __Label_h__
