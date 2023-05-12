#ifndef SGD_GAME_PLAYER_H
#define SGD_GAME_PLAYER_H

#include "character.h"
#include "../animation/animation.h"
#include "../physics/rigidbody.h"
#include "../collision/collider.h"

class Player : public Character {
public:
    Player(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
    bool getKeyDown(SDL_Scancode key);
    void keyUp();
    void keyDown();
    virtual void draw();
    virtual void clean();
    virtual void update(float dt);
    SDL_RendererFlip getFlip();
    void setFlip(SDL_RendererFlip flip);
    void handleEvents();
    Collider* getCollider();
    inline int getPlayerWidth() { return width; }
    inline int getPlayerHeight() { return height; }

private:
    const Uint8* keyState;
    bool isJumping;
    bool isGrounded;

    float JUMPTIME = 15.0f;

    float jumpTime;
    float jumpForce;

    // box with collision around the player
    Collider* collider;

    Vector2D lastSafePosition;

    Animation* animation;
    RigidBody* rigidBody;

};

#endif //SGD_GAME_PLAYER_H
