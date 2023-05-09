#include "animation.h"
#include "../render/render.h"

void Animation::update() {
    // if modulo equals 0 then it is the last frame and we start from the first
    spriteFrame = (SDL_GetTicks() / animationSpeed) % frameCount;
}

void Animation::draw(float x, float y, int spriteWidth, int spriteHeight, SDL_RendererFlip flip) {
    Render::getInstance()->drawFrame(textureId, x, y, spriteWidth, spriteHeight, spriteRow, spriteFrame, flip);
}

void Animation::setProperties(std::string textureId, int spriteRow, int frameCount,
                   int animationSpeed) {
    this->textureId = textureId;
    this->spriteRow = spriteRow;
    this->frameCount = frameCount;
    this->animationSpeed = animationSpeed;
}