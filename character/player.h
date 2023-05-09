#ifndef SGD_GAME_PLAYER_H
#define SGD_GAME_PLAYER_H

#include "character.h"

class Player : public Character {
public:
    Player(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
    virtual void draw();
    virtual void clean();
    virtual void update(float dt);

private:
    // frameCount - how much frames will be drawn for animation
    int row, frame, frameCount, animationSpeed;

};

#endif //SGD_GAME_PLAYER_H
