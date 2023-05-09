#ifndef SGD_GAME_CHARACTER_H
#define SGD_GAME_CHARACTER_H

#include "../physics/transform.h"

#include <SDL.h>

// player and NPCs objects interface
class Character {
public:
    Character(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE) {
        this->textureId = textureId;
        transform = new Transform(x, y);
        this->width = width;
        this->height = height;
        this->flip = flip;
    }
    virtual void draw() = 0;
    virtual void clean() = 0;
    virtual void update(float dt) = 0;

protected:
    std::string name;
    Transform* transform;
    int width, height;
    std::string textureId;
    SDL_RendererFlip flip;
};

#endif //SGD_GAME_CHARACTER_H
