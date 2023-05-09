#include "game.h"

#include <iostream>

Game* Game::game = nullptr;
Player* player = nullptr;

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
    Render::getInstance()->loadTexture("clouds", "clouds.bmp");
    Render::getInstance()->loadTexture("background", "background.bmp");
    Render::getInstance()->loadTexture("floor", "floor_placeholder.bmp");

    player = new Player("player", 0, 358, 64, 64);

    running = true;
}


void Game::handleEvents() {
        SDL_Event e;
        auto *key_state = SDL_GetKeyboardState(nullptr);
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
                case SDL_QUIT:
                    std::cout << "Quit" << std::endl;
                    quit();
                    break;
            }
        }

//        player_texture = render.loadTexture(renderer_p, "player-right.bmp");
        //    if (key_state[SDL_SCANCODE_UP]) player.getPlayerRect().y--;
//        if (key_state[SDL_SCANCODE_UP]) rect.y--;
//        if (key_state[SDL_SCANCODE_DOWN]) rect.y++;
//        if (key_state[SDL_SCANCODE_LEFT]) {
////            player_texture = render.loadTexture(renderer_p, "player-left.bmp");
//            flipHorizontally = true;
//            rect.x--;
//        }
//        if (key_state[SDL_SCANCODE_RIGHT]) {
//            //        player_texture = render.loadTexture(renderer_p, "player.bmp");
//            flipHorizontally = false;
//            rect.x++;
//        }
}

void Game::update() {
//    previousTick = currentTick;
//    currentTick = SDL_GetTicks();
//    if ((currentTick - previousTick) < 33) {
//        SDL_Delay(33 - (currentTick - previousTick));
//        frameDropped = 0;
//    } else {
//        frameDropped = 1;
//    }
//    previousTick += 33;
    player->update(0);

}

// render everything, draw textures
void Game::render() {
    SDL_SetRenderDrawColor(renderer, 124, 218, 254, 255);
    SDL_RenderClear(renderer);

    Render::getInstance()->drawTexture("background", 0, 0, 1043, 613);
    Render::getInstance()->drawTexture("clouds", -200, -125, 979, 602);
    for (int i=0; i<16; i++) {
        Render::getInstance()->drawTexture("floor", 0+i*64, 416, 64, 64);
    }

    SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;
    if (flipHorizontally) flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
    // copy texture to the renderer, dstrect is stretching to entire screen
//    Render::getInstance()->drawTexture("player", 0, 325, 100, 100, flip);
    player->draw();

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
