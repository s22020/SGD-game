#include "render.h"

#include <iostream>
#include <memory>

Render::Render(int windowWidth, int windowHeight) {
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
}

Render::Render() {}

std::pair<std::shared_ptr<SDL_Window>, std::shared_ptr<SDL_Renderer>> Render::initializeWindow() {
    SDL_Window *window;
    SDL_Renderer *renderer;
    // create window and renderer for displaying textures etc
    SDL_CreateWindowAndRenderer(
            640, 480,
            SDL_WINDOW_SHOWN,
            &window,
            &renderer);
    std::shared_ptr<SDL_Window> w(window, [](SDL_Window *window) {
        SDL_DestroyWindow(window);
    });
    std::shared_ptr<SDL_Renderer> r(renderer, [](SDL_Renderer *renderer) {
        SDL_DestroyRenderer(renderer);
    });
    return {w, r};
}

std::shared_ptr<SDL_Texture> Render::loadTexture(std::shared_ptr<SDL_Renderer> renderer, std::string textureName) {
    auto surface = SDL_LoadBMP(("assets/" + textureName).c_str());
    if (!surface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());
        throw std::invalid_argument(SDL_GetError());
    }
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0x0ff, 0x0, 0x0ff));
    SDL_SetColorKey(surface, SDL_TRUE, 0x0ff00ff);
    auto texture = SDL_CreateTextureFromSurface(renderer.get(), surface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
        throw std::invalid_argument(SDL_GetError());
    }
    SDL_FreeSurface(surface);
    return std::shared_ptr<SDL_Texture>(texture, [](auto *p) { SDL_DestroyTexture(p); });
}

std::pair<int, int> Render::getTextureWidthHeight(std::shared_ptr<SDL_Texture> texture) {
    int w, h;
    // get info about texture size
    SDL_QueryTexture(texture.get(), nullptr, nullptr, &w, &h);
    return {w, h};
}
// return the size of texture
SDL_Rect Render::getTextureRect(std::shared_ptr<SDL_Texture> texture) {
    auto [w, h] = getTextureWidthHeight(texture);
    return {0, 0, w, h};
}