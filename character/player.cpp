#include "player.h"
#include "../render/render.h"

Player::Player(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip)
                : Character(textureId, x, y, width, height, flip) {
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
    animation->update();
}

//void Player::setFlipHorizontally(bool flipHorizontally) {
//    this->flipHorizontally = flipHorizontally;
//}