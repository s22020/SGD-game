//#include <SDL.h>
//#include <SDL_image.h>
#include "core/game.h"


int main() {
    Game::getInstance()->startGame();
    while(Game::getInstance()->isRunning()) {
        Game::getInstance()->handleEvents();
        Game::getInstance()->update();
        Game::getInstance()->render();
    }
    Game::getInstance()->clean();
    return 0;
}
