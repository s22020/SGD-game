#ifndef SGD_GAME_PLAYER_H
#define SGD_GAME_PLAYER_H

#include "character.h"
#include "../animation/animation.h"
#include "../physics/rigidbody.h"

class Player : public Character {
public:
    Player(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
    virtual void draw();
    virtual void clean();
    virtual void update(float dt);
    SDL_RendererFlip getFlip();
    void setFlip(SDL_RendererFlip flip);
    void handleEvents();

private:
    Animation* animation;
    RigidBody* rigidBody;

};

#endif //SGD_GAME_PLAYER_H
