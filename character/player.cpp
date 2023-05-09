#include "player.h"
#include "../render/render.h"

Player::Player(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip)
                : Character(textureId, x, y, width, height, flip) {
    rigidBody = new RigidBody();
    animation = new Animation();
    animation->setProperties(textureId, 0, 3, 500);
}

void Player::draw() {
    animation->draw(transform->posX, transform->posY, width, height);
}

void Player::clean() {
    Render::getInstance()->clean();
}

void Player::update(float dt) {
    rigidBody->calculateAppliedForces(0.5);
    transform->translateX(rigidBody->getPosition().posX);
    transform->translateY(rigidBody->getPosition().posY);
    animation->update();
}

//void Player::setFlipHorizontally(bool flipHorizontally) {
//    this->flipHorizontally = flipHorizontally;
//}