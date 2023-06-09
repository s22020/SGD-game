#ifndef SGD_GAME_OBJECT_H
#define SGD_GAME_OBJECT_H

#include "../physics/transform.h"

#include <SDL.h>

// interface object for inanimate game objects
class Object {
public:
    Object(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE) {
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
    Transform* transform;
    int width, height;
    std::string textureId;
    SDL_RendererFlip flip;
};


#endif //SGD_GAME_OBJECT_H
