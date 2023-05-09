#ifndef SGD_GAME_ANIMATION_H
#define SGD_GAME_ANIMATION_H

#include <SDL.h>

#include <iostream>

class Animation {
public:
    Animation() {}
    void update();
    void draw(float x, float y, int spriteWidth, int spriteHeight, SDL_RendererFlip flip);
    void setProperties(std::string textureId, int spriteRow, int frameCount,
                       int animationSpeed);

private:
    // frameCount - how much frames will be drawn for animation
    int spriteRow, spriteFrame, animationSpeed, frameCount;
    std::string textureId;
//    SDL_RendererFlip flip;

};

#endif //SGD_GAME_ANIMATION_H
