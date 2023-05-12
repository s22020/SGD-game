#include "game.h"
#include "../character/enemy.h"
#include "../collision/collisionhandler.h"

#include <iostream>

Game* Game::game = nullptr;
//LevelMap* levelMap = new LevelMap(64);

Player* player = new Player("player", 0, 200, 64, 64);

//Player* player = new Player("player", 0, 356, 64, 64);
Enemy* enemy1 = new Enemy("enemy1", 20, 358, 64, 64);


void Game::startGame() {
    // ROZWIAZANIE ZAGADKI
//    deltaTime =  0.5f;
    if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        running = false;
    }
    window = SDL_CreateWindow("Kapibara", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    if (window == nullptr) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        running = false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        running = false;
    }


    // load every Texture
    Render::getInstance()->loadTexture("player", "player-idle.png");
    Render::getInstance()->loadTexture("player-run", "player-run.png");
    Render::getInstance()->loadTexture("player-shoot", "player-shoot.png");
    Render::getInstance()->loadTexture("background1", "background1.png");
    Render::getInstance()->loadTexture("background2", "background2.png");
    Render::getInstance()->loadTexture("background3", "background3.png");

    Render::getInstance()->loadTexture("floor", "floor.png");
    Render::getInstance()->loadTexture("enemy1", "enemy.png");

//    player = new Player("player", 0, 358, 64, 64);
//  ODKOMENTUJ JESLI NIE DZIALA
    levelMap = new LevelMap(16);

    running = true;
}


void Game::handleEvents() {
    player->handleEvents();
}

void Game::calculateDeltaTime() {
    float currentTime;
    currentTime = SDL_GetTicks();
    deltaTime = (currentTime - previousTime) * (targetFPS/1000.0f);
    if (deltaTime > maxDeltaTime) {
        deltaTime = maxDeltaTime;
    }
    previousTime = SDL_GetTicks();
}

void Game::update() {
    player->update(deltaTime);
}

// render everything, draw textures
void Game::render() {
    SDL_SetRenderDrawColor(renderer, 124, 218, 254, 255);
    SDL_RenderClear(renderer);

    Render::getInstance()->drawTexture("background1", 0, 0, 640, 640);
    Render::getInstance()->drawTexture("background2", 0, 0, 640, 640);
    Render::getInstance()->drawTexture("background3", 0, 0, 640, 640);
    // to jest moja collision layer
    // tutaj zamienic na dlugosc wektora z mapy
    for (int i=0; i<levelMap->getFloorCount(); i++) {
        // napisać funkcję getRectangle dla render i character
        Render::getInstance()->drawTexture("floor", 0+i*64, 416, 64, 64);

    }
    player->draw();

    // render enemy
    Render::getInstance()->drawTexture("enemy1", 450, 358, 64,64, SDL_FLIP_HORIZONTAL);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    Render::getInstance()->clean();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Game::quit() {
    running = false;
}
