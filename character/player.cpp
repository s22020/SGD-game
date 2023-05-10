#include "player.h"
#include "../render/render.h"
#include "../core/game.h"

Player::Player(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip)
                : Character(textureId, x, y, width, height, flip) {
    rigidBody = new RigidBody();
    animation = new Animation();
    animation->setProperties(textureId, 0, 3, 500);
}

void Player::draw() {
    animation->draw(transform->posX, transform->posY, width, height, flip);
}

void Player::clean() {
    Render::getInstance()->clean();
}

void Player::update(float dt) {
    rigidBody->calculateAppliedForces(dt);
    transform->translateX(rigidBody->getPosition().posX);
//    transform->translateY(rigidBody->getPosition().posY);
    animation->update();
}

SDL_RendererFlip Player::getFlip() {
    return flip;
}

void Player::setFlip(SDL_RendererFlip flip) {
    this->flip = flip;
}

void Player::handleEvents() {
        SDL_Event e;
        auto *key_state = SDL_GetKeyboardState(nullptr);
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
                case SDL_QUIT:
                    std::cout << "Quit" << std::endl;
                    Game::getInstance()->quit();
                    break;
            }
        }

        animation->setProperties("player", 0, 3, 500);
        rigidBody->unsetForce();
        if (key_state[SDL_SCANCODE_RIGHT]) {
            rigidBody->setForceX(3);
            setFlip(SDL_FLIP_NONE);
            animation->setProperties("player-run", 0, 2, 200);

        }
        if (key_state[SDL_SCANCODE_LEFT]) {
            rigidBody->setForceX(-3);
            setFlip(SDL_FLIP_HORIZONTAL);
            animation->setProperties("player-run", 0, 2, 200);
        }

        if (key_state[SDL_SCANCODE_X]) {
            animation->setProperties("player-shoot", 0, 2, 150);
        }
}