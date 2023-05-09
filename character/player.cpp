#include "player.h"
#include "../render/render.h"

// updates frame according to animationSpeed
Player::Player(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip)
                : Character(textureId, x, y, width, height, flip) {
    // how much "frames" in spritesheet the player animation has
    row = 0;
    frameCount = 2;
    animationSpeed = 500;
}

void Player::draw() {
    Render::getInstance()->drawFrame(textureId, transform->posX, transform->posY, width, height, row, frame);
}

void Player::clean() {
    Render::getInstance()->clean();
}

void Player::update(float dt) {
    // if modulo equals 0 then it is the last frame and we start from the first
    frame = (SDL_GetTicks() / animationSpeed) % frameCount;
}

//void Player::setFlipHorizontally(bool flipHorizontally) {
//    this->flipHorizontally = flipHorizontally;
//}