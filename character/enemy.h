#ifndef SGD_GAME_ENEMY_H
#define SGD_GAME_ENEMY_H

#include "character.h"
#include "../animation/animation.h"
#include "../physics/rigidbody.h"

class Enemy : public Character {
public:
    Enemy(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
    virtual void draw();
    virtual void clean();
    virtual void update(float dt);
    SDL_RendererFlip getFlip();
    void setFlip(SDL_RendererFlip flip);

private:
    Animation* animation;
    RigidBody* rigidBody;

};

#endif //SGD_GAME_ENEMY_H
