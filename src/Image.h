//
// Created by aroldan
//

#ifndef __Image_h__
#define __Image_h__

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Image {
public:
    Image();
    virtual ~Image();

    bool load(const std::string& filename);

    void render(int x, int y, SDL_Renderer* renderer);
    void render(int x, int y, int w, int h, SDL_Renderer* renderer);

    void release();

private:
    SDL_Surface *surface;
    SDL_Texture *texture;
};


#endif // __Image_h__
