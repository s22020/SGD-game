#ifndef SGD_GAME_PLAYER_H
#define SGD_GAME_PLAYER_H

#include <SDL.h>

#include <memory>

class Player {
public:
    SDL_Rect getTextureRect(std::shared_ptr<SDL_Texture> texture);

private:
    std::pair<int, int> getTextureWH(std::shared_ptr<SDL_Texture> texture);
};

#endif //SGD_GAME_PLAYER_H
