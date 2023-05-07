#ifndef SGD_GAME_PLAYER_H
#define SGD_GAME_PLAYER_H

#include <SDL.h>

#include <memory>

class Player {
public:
    SDL_Rect &getPlayerRect();

private:
    SDL_Rect playerRect = {0, 0, 100, 100};

};

#endif //SGD_GAME_PLAYER_H
