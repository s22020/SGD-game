#include "player.h"
#include "../render/render.h"
#include "../core/game.h"
#include "../collision/collider.h"
#include "../collision/collisionhandler.h"
#include "../render/levelmap.h"



Player::Player(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip)
                : Character(textureId, x, y, width, height, flip) {
//    jumpTime = 15.0f;
//    jumpForce = 10.0f;
//
    collider = new Collider();
    collider->setMargin(0, 0, 0, 0);


    rigidBody = new RigidBody();
    rigidBody->setGravity(3.0f);

    animation = new Animation();
    animation->setProperties(textureId, 0, 3, 500);
}

void Player::draw() {
    animation->draw(transform->posX, transform->posY, width, height, flip);

//    ======== COLLIDER ==========
    SDL_Rect box = collider->getBox();
    SDL_RenderDrawRect(Game::getInstance()->getRenderer(), &box);
//    ======== COLLIDER ==========

}

void Player::clean() {
    Render::getInstance()->clean();
//    Render::getInstance()->dropTexture(textureId);
}

void Player::update(float dt) {
    // ZAKOMENTUJ JESLI NIE DZIALA
//    Game::getInstance()->levelMap = new LevelMap(64);

    animation->setProperties("player", 0, 3, 500);
    rigidBody->unsetForce();

    if (getKeyDown(SDL_SCANCODE_RIGHT)) {
        rigidBody->setForceX(3);
        setFlip(SDL_FLIP_NONE);
        animation->setProperties("player-run", 0, 2, 200);

    }
    if (getKeyDown(SDL_SCANCODE_LEFT)) {
        rigidBody->setForceX(-3);
        setFlip(SDL_FLIP_HORIZONTAL);
        animation->setProperties("player-run", 0, 2, 200);
    }

    if (getKeyDown(SDL_SCANCODE_X)) {
        animation->setProperties("player-shoot", 0, 2, 100);
    }

    // ============= JUMPING ==================

//    if (getKeyDown(SDL_SCANCODE_Z) && isGrounded) {
//        isJumping = true;
//        isGrounded = false;
//        rigidBody->setForceY(1*jumpForce);
//    }
//
//    if (getKeyDown(SDL_SCANCODE_Z) && isJumping && jumpTime > 0) {
//        jumpTime -= dt;
//        rigidBody->setForceY((-1) * jumpForce);
//    } else {
//        isJumping = false;
//        jumpTime = JUMPTIME;
//    }


    // ZBIĆ SZYBKĘ W RAZIE AWARII
//    rigidBody->calculateAppliedForces(dt);
//    transform->translateX(rigidBody->getPosition().posX);
//    std::cout << "rigid body Y:" << rigidBody->getPosition().posY << std::endl;
//    transform->translateY(rigidBody->getPosition().posY);

    // ZBIĆ SZYBKĘ W RAZIE AWARII

    rigidBody->calculateAppliedForces(dt);
    lastSafePosition.posX = transform->posX;
    lastSafePosition.posY = transform->posY;
    std::cout << "last safe position x: " << lastSafePosition.posX << std::endl;
    std::cout << "last safe position y: " << lastSafePosition.posY << std::endl;
    transform->translateX(rigidBody->getPosition().posX);
    transform->translateY(rigidBody->getPosition().posY);

    SDL_Rect playerRect = {static_cast<int>(transform->posX), static_cast<int>(transform->posY), getPlayerWidth(), getPlayerHeight()};
    std::cout << "playerRect.x " << playerRect.x << std::endl;
    std::cout << "playerRect.y " << playerRect.y << std::endl;
    // map collider = {0, 416, 0+i*64, 64}
    SDL_Rect mapRect = {0, 416, 0+16*64, 64};
    if (SDL_HasIntersection(&playerRect, &mapRect)) {
        transform->posX = lastSafePosition.posX;
        transform->posY = lastSafePosition.posY;
    }

    rigidBody->calculateAppliedForces(dt);


    lastSafePosition.posX = transform->posX;
    lastSafePosition.posY = transform->posY;

    transform->translateX(rigidBody->getPosition().posX);

    animation->update();
}

SDL_RendererFlip Player::getFlip() {
    return flip;
}

void Player::setFlip(SDL_RendererFlip flip) {
    this->flip = flip;
}

bool Player::getKeyDown(SDL_Scancode key) {
    return (keyState[key] == 1);
}

void Player::keyUp() {
    keyState = SDL_GetKeyboardState(nullptr);
}

void Player::keyDown() {
    keyState = SDL_GetKeyboardState(nullptr);
}

void Player::handleEvents() {
        SDL_Event e;
        keyState = SDL_GetKeyboardState(nullptr);
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    std::cout << "Quit" << std::endl;
                    Game::getInstance()->quit();
                    break;
                case SDL_KEYDOWN:
                    keyDown();
                    break;
                case SDL_KEYUP:
                    keyUp();
                    break;
            }
        }
}

Collider* Player::getCollider() {
    return collider;
}