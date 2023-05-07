#ifndef SGD_GAME_GAME_H
#define SGD_GAME_GAME_H
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "../render/render.h"
#include "../objects/player.h"

class Game {
private:
    bool gaming;
    Render render;
    Player player;
    int frameDropped = 0;
    Uint32 previousTick = 0;
    Uint32 currentTick = SDL_GetTicks();
    double deltaTime = 0;

    void startGame();
    void handleEvents(SDL_Rect &sdlRect);
    void updateWithDelta();

public:
    Game(int windowWidth, int windowHeight);
};

#endif //SGD_GAME_GAME_H
