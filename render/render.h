#ifndef SGD_GAME_RENDER_H
#define SGD_GAME_RENDER_H

#include <SDL.h>

#include <iostream>
#include <memory>

class Render {
private:
    int windowWidth;
    int windowHeight;
//    SDL_Window *window;
//    SDL_Renderer *renderer;
    std::pair<int, int> getTextureWH(std::shared_ptr<SDL_Texture> texture);

public:
    Render(int windowWidth, int windowHeight);
    Render();
    std::pair<std::shared_ptr<SDL_Window>, std::shared_ptr<SDL_Renderer>> initializeWindow();
    std::shared_ptr<SDL_Texture> loadTexture(std::shared_ptr<SDL_Renderer> renderer, std::string textureName);
    SDL_Rect getTextureRect(std::shared_ptr<SDL_Texture> texture);

};

#endif //SGD_GAME_RENDER_H
