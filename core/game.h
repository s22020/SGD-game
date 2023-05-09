#define SDL_MAIN_HANDLED
#ifndef SGD_GAME_GAME_H
#define SGD_GAME_GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include "../render/render.h"
#include "../character/player.h"

class Game {
public:
    static Game* getInstance() {
        return game = (game != nullptr) ? game : new Game();
    }

    void startGame();
    void handleEvents();
    void update();
    void render();
    void clean();
    void quit();

    inline bool isRunning() { return running; }
    inline SDL_Renderer* getRenderer() { return renderer; }

private:
    Game() {}
    static Game* game;
    bool running;
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool flipHorizontally = false;
};

#endif //SGD_GAME_GAME_H
