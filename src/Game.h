//
// Created by aroldan
//

#ifndef __Game_h__
#define __Game_h__


#include <cstdint>
#include <string>
#include <SDL2/SDL.h>
#include "Image.h"

class Game {
public:
    Game();
    Game(const std::string& name, uint32_t released, uint8_t players, const std::string& cover, const std::string& image);
    virtual ~Game();

    const std::string& getName() const;
    void setName(const std::string& name);
    uint32_t getReleased() const;
    void setReleased(uint32_t released);
    uint8_t getPlayers() const;
    void setPlayers(uint8_t players);
    Image& getCoverImage();
    const std::string &getImage() const;
    void setImage(const std::string &image);

    bool create();

private:
    std::string name;
    uint32_t released;
    uint8_t players;
    Image coverImage;
    std::string cover;
    std::string image;

};


#endif // __Game_h__