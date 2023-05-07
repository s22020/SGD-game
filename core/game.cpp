#include "game.h"
#include "../render/render.h"

#include <iostream>

void Game::updateWithDelta() {
    previousTick = currentTick;
    currentTick = SDL_GetTicks();
    if ((currentTick - previousTick) < 33) {
        SDL_Delay(33 - (currentTick - previousTick));
        frameDropped = 0;
    } else {
        frameDropped = 1;
    }
    previousTick += 33;

}

void Game::handleEvents(SDL_Rect &rect) {
    SDL_Event e;
    auto *key_state = SDL_GetKeyboardState(nullptr);
    while (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                std::cout << "Quit" << std::endl;
                gaming = false;
                break;
        }
    }
    if (key_state[SDL_SCANCODE_UP]) rect.y--;
    if (key_state[SDL_SCANCODE_DOWN]) rect.y++;
    if (key_state[SDL_SCANCODE_LEFT]) rect.x--;
    if (key_state[SDL_SCANCODE_RIGHT]) rect.x++;
}

void Game::startGame() {
    SDL_Init(SDL_INIT_EVERYTHING);
    gaming = true;
    auto [window_p, renderer_p] = render.initializeWindow();

    // create player texture
    auto player_texture = render.loadTexture(renderer_p, "player.bmp");
    SDL_Rect player_rect = player.getTextureRect(player_texture);

    auto clouds = render.loadTexture(renderer_p, "clouds.bmp");
    auto background = render.loadTexture(renderer_p, "background.bmp");


    int frame_dropped = 0;
    while (gaming) {
        if (!frame_dropped) {
//                SDL_RenderClear(renderer_p.get());
            SDL_RenderCopy(renderer_p.get(), background.get(), nullptr, nullptr);
            int w;
            int h;
            SDL_QueryTexture(clouds.get(), NULL, NULL, &w, &h);
            SDL_Rect clouds_rect = {player_rect.x / 2 - 200, player_rect.y / 2 - 200, w, h};
            SDL_RenderCopy(renderer_p.get(), clouds.get(), nullptr, &clouds_rect);
            // copy a player texture to the renderer
            SDL_RenderCopy(renderer_p.get(), player_texture.get(), nullptr, &player_rect);
//            render.playerRender(renderer_p);
            SDL_RenderPresent(renderer_p.get());
            updateWithDelta();
            handleEvents(player_rect);

        }
    }
    SDL_Quit();
}

Game::Game(int windowWidth, int windowHeight) {
    this->render = Render(windowWidth, windowHeight);

    startGame();
}