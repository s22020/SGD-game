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

//    ======== COLLIDER ==========
//    rigidBody->calculateAppliedForces(dt);
//    lastSafePosition.posX = transform->posX;
//    lastSafePosition.posY = transform->posY;
//    transform->translateX(rigidBody->getPosition().posX);
//    transform->translateY(rigidBody->getPosition().posY);
//    std::cout << "rigid body posY " << rigidBody->getPosition().posY << std::endl;
//    collider->setBox(transform->posX, transform->posY, 96, 96);

//    bool collisionDetected = false;
//    for (int i = 0; i < Game::getInstance()->levelMap->getFloorLayer().size(); i++) {
//        if (CollisionHandler::getInstance()->checkCollision(getCollider()->getBox(),
//                                                            Game::getInstance()->levelMap->getFloorLayer()[i])) {
//            collisionDetected = true;
//            rigidBody->calculateAppliedForces(dt);
//            transform->posX = lastSafePosition.posX;
//            std::cout << transform->posX << std::endl;
//        }
//        rigidBody->calculateAppliedForces(dt);
//        if (collisionDetected) {
//            lastSafePosition.posY = transform->posY;
//        }
//        transform->translateY(rigidBody->getPosition().posY);
//        collider->setBox(transform->posX, transform->posY, 96, 96);
//
//        if (CollisionHandler::getInstance()->checkCollision(getCollider()->getBox(),
//                                                            Game::getInstance()->levelMap->getFloorLayer()[i])) {
//            isGrounded = true;
//            transform->posY = lastSafePosition.posY;
//        } else {
//            isGrounded = false;
//        }
//        // napisać funkcję getRectangle dla render i character
//        // przenieśc do game
////        Render::getInstance()->drawTexture("floor", 0+i*64, 416, 64, 64);
//    }
//    ======== COLLIDER ==========


    // ZBIĆ SZYBKĘ W RAZIE AWARII
//    rigidBody->calculateAppliedForces(dt);
//    transform->translateX(rigidBody->getPosition().posX);
//    std::cout << "rigid body Y:" << rigidBody->getPosition().posY << std::endl;
//    transform->translateY(rigidBody->getPosition().posY);

    // ZBIĆ SZYBKĘ W RAZIE AWARII

    // EXPERYMENT //
    rigidBody->calculateAppliedForces(dt);
    lastSafePosition.posX = transform->posX;
    lastSafePosition.posY = transform->posY;
    std::cout << "last safe position x: " << lastSafePosition.posX << std::endl;
    std::cout << "last safe position y: " << lastSafePosition.posY << std::endl;
    transform->translateX(rigidBody->getPosition().posX);
    transform->translateY(rigidBody->getPosition().posY);
//    std::cout << "player posX: " << transform->posX << std::endl;
//    std::cout << "player posY: " << transform->posY << std::endl;
    collider->setBox(transform->posX, transform->posY, 96, 96);
    SDL_Rect playerRect = {static_cast<int>(transform->posX), static_cast<int>(transform->posY), getPlayerWidth(), getPlayerHeight()};
    for (int i = 0; i < Game::getInstance()->levelMap->getFloorLayer().size(); i++) {
        std::cout << "player posX: " << transform->posX << std::endl;
        std::cout << "player posY: " << transform->posY << std::endl;
        std::cout << "map rect pos x: " << Game::getInstance()->levelMap->getFloorLayer()[i].x <<  std::endl;
        std::cout << "map rect pos y: " << Game::getInstance()->levelMap->getFloorLayer()[i].y <<  std::endl;
//        if (SDL_HasIntersection(&playerRect, &Game::getInstance()->levelMap->getFloorLayer()[i])) {
        if (transform->posX == Game::getInstance()->levelMap->getFloorLayer()[i].x && transform->posY == Game::getInstance()->levelMap->getFloorLayer()[i].y) {
            std::cout << "===================== intersection ===================" << std::endl;
//            rigidBody->calculateAppliedForces(dt);
            transform->posX = lastSafePosition.posX;
            transform->posY = lastSafePosition.posY;
        }
    }
//    transform->translateX(rigidBody->getPosition().posX);
//    transform->translateY(rigidBody->getPosition().posY);

    animation->update();


//    bool collisionDetected = false;
//    for (int i=0; i < levelMap->getFloorLayer().size(); i++) {
//        if (CollisionHandler::getInstance()->checkCollision(player->getCollider()->getBox(), levelMap->getFloorLayer()[i])) {
//            collisionDetected = true;
//            lastSafePosition =
//        }
//        // napisać funkcję getRectangle dla render i character
//        Render::getInstance()->drawTexture("floor", 0+i*64, 416, 64, 64);
//}
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