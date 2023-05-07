#include "game.h"
#include "../render/render.h"

#include <iostream>
#include <vector>

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

//void Game::handleEvents(SDL_Rect &rect, std::shared_ptr<SDL_Texture> player_texture ,std::shared_ptr<SDL_Renderer> renderer_p) {
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

//        player_texture = render.loadTexture(renderer_p, "player-right.bmp");
        //    if (key_state[SDL_SCANCODE_UP]) player.getPlayerRect().y--;
        if (key_state[SDL_SCANCODE_UP]) rect.y--;
        if (key_state[SDL_SCANCODE_DOWN]) rect.y++;
        if (key_state[SDL_SCANCODE_LEFT]) {
//            player_texture = render.loadTexture(renderer_p, "player-left.bmp");
            player.setFlipHorizontally(true);
            rect.x--;
        }
        if (key_state[SDL_SCANCODE_RIGHT]) {
            //        player_texture = render.loadTexture(renderer_p, "player.bmp");
            player.setFlipHorizontally(false);
            rect.x++;
        }
}

void Game::startGame() {
    SDL_Init(SDL_INIT_EVERYTHING);
    gaming = true;
    auto [window_p, renderer_p] = render.initializeWindow();

    // create player texture
    auto player_texture = render.loadTexture(renderer_p, "player.bmp");
//    SDL_Rect player_rect = player.getTextureRect(player_texture);
    SDL_Rect player_rect = player.getPlayerRect();

    auto clouds = render.loadTexture(renderer_p, "clouds.bmp");
    auto background = render.loadTexture(renderer_p, "background.bmp");
    auto floor = render.loadTexture(renderer_p, "floor_placeholder.bmp");

    int frame_dropped = 0;
    while (gaming) {
        if (!frame_dropped) {
//                SDL_RenderClear(renderer_p.get());
            // copy texture to the renderer, dstrect is stretching to entire screen
            SDL_RenderCopy(renderer_p.get(), background.get(), nullptr, nullptr);
            std::vector<SDL_Rect> floor_array = std::vector<SDL_Rect>();
//            SDL_Rect floor_rect = {0, 416+i*32, 64, 64};
            for (int i=0; i<16; i++) {
                SDL_Rect floor_rect = {0+i*64, 416, 64, 64};
                floor_array.push_back(floor_rect);
                SDL_RenderCopy(renderer_p.get(), floor.get(), nullptr, &floor_rect);
            }
            int w;
            int h;
            // ask the size of texture and copy to w and h
            SDL_QueryTexture(clouds.get(), NULL, NULL, &w, &h);
//            render.getTextureRect(clouds);
            SDL_Rect clouds_rect = {player_rect.x / 2 - 200, player_rect.y / 2 - 200, w, h};
            SDL_RenderCopy(renderer_p.get(), clouds.get(), nullptr, &clouds_rect);
            handleEvents(player_rect);
            SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;
            // copy a player texture to the renderer
            if (player.getFlipHorizontally()) flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
            SDL_RenderCopyEx(renderer_p.get(), player_texture.get(), nullptr, &player_rect, 0, nullptr, flip);
//            render.playerRender(renderer_p);
            SDL_RenderPresent(renderer_p.get());
            updateWithDelta();
//            handleEvents(player_rect, player_texture, renderer_p);



        }
    }
    SDL_Quit();
}

Game::Game(int windowWidth, int windowHeight) {
    this->render = Render(windowWidth, windowHeight);
    this->player = Player(0, 325, 100, 100);

    startGame();
}