#include "game.h"
#include "../animation/animation.h"
#include "../physics/rigidbody.h"
#include "../character/enemy.h"

#include <iostream>

Game* Game::game = nullptr;
//Player* player = nullptr;

Player* player = new Player("player", 0, 358, 64, 64);
Enemy* enemy1 = new Enemy("enemy1", 20, 358, 64, 64);


void Game::startGame() {
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
    Render::getInstance()->loadTexture("clouds", "clouds.bmp");
    Render::getInstance()->loadTexture("background", "background.bmp");
    Render::getInstance()->loadTexture("floor", "floor_placeholder.bmp");
    Render::getInstance()->loadTexture("enemy1", "enemy.png");

//    player = new Player("player", 0, 358, 64, 64);

    running = true;
}


void Game::handleEvents() {
    player->handleEvents();
}

void Game::calculateDeltaTime() {
    float currentTime;
//    previousTime = 0.0f;
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

    Render::getInstance()->drawTexture("background", 0, 0, 1043, 613);
    Render::getInstance()->drawTexture("clouds", -200, -125, 979, 602);
    for (int i=0; i<64; i++) {
        Render::getInstance()->drawTexture("floor", 0+i*64, 416, 64, 64);
    }

//    SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;
//    if (flipHorizontally) flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
    // copy texture to the renderer, dstrect is stretching to entire screen
//    Render::getInstance()->drawTexture("player", 0, 325, 100, 100, flip);
    player->draw();
//    enemy1->draw();
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
