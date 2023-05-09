#include "render.h"
#include "../core/game.h"

#include <iostream>

Render* Render::render = nullptr;

bool Render::loadTexture(std::string id, std::string fileName) {
    SDL_Surface* surface = IMG_Load(("assets/" + fileName).c_str());
    if (surface == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s, %s", ("assets/" + fileName).c_str(), SDL_GetError());
        return false;
    }
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0x0ff, 0x0, 0x0ff));
    SDL_SetColorKey(surface, SDL_TRUE, 0x0ff00ff);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::getInstance()->getRenderer(), surface);
    if (texture == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
        return false;
    }
//    SDL_FreeSurface(surface);
    renderMap[id] = texture;
    return true;
}

void Render::drawTexture(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip) {
    // which part of texture should be loaded
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect dstRect = {x, y, width, height};

    SDL_RenderCopyEx(Game::getInstance()->getRenderer(), renderMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void Render::drawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip) {
    SDL_Rect srcRect = {width * frame, height * row, width, height};
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopyEx(Game::getInstance()->getRenderer(), renderMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void Render::dropTexture(std::string id) {
    SDL_DestroyTexture(renderMap[id]);
    renderMap.erase(id);
}

// iterator for cleaning everything from map
void Render::clean() {
    std::map<std::string, SDL_Texture*>::iterator it;
    for(it=renderMap.begin(); it != renderMap.end(); it++) {
        SDL_DestroyTexture(it->second);
    }
    renderMap.clear();

    SDL_Log("render map cleared");
}

//std::pair<int, int> Render::getTextureWidthHeight(std::shared_ptr<SDL_Texture> texture) {
//    int w, h;
//    // get info about texture size
//    SDL_QueryTexture(texture.get(), nullptr, nullptr, &w, &h);
//    return {w, h};
//}
//// return the size of texture
//SDL_Rect Render::getTextureRect(std::shared_ptr<SDL_Texture> texture) {
//    auto [w, h] = getTextureWidthHeight(texture);
//    return {0, 0, w, h};
//}