#ifndef SGD_GAME_RENDER_H
#define SGD_GAME_RENDER_H

#include <SDL.h>

#include <iostream>
#include <memory>

class Render {
private:
    int windowWidth;
    int windowHeight;
    std::pair<int, int> getTextureWidthHeight(std::shared_ptr<SDL_Texture> texture);

public:
    Render(int windowWidth, int windowHeight);
    Render();
    std::pair<std::shared_ptr<SDL_Window>, std::shared_ptr<SDL_Renderer>> initializeWindow();
    // move to private
    std::shared_ptr<SDL_Texture> loadTexture(std::shared_ptr<SDL_Renderer> renderer, std::string textureName);
    // move to private

    SDL_Rect getTextureRect(std::shared_ptr<SDL_Texture> texture);

    // add main render method
//    void render();
    // add playerRender method
//    void render(std::shared_ptr<SDL_Renderer> renderer_p);
    // add backgroundRender method
//    void backgroundRender();
    // add floorRender method
//    void floorRender();

};

#endif //SGD_GAME_RENDER_H
