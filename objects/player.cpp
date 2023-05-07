#include "player.h"

std::pair<int, int> Player::getTextureWH(std::shared_ptr<SDL_Texture> texture) {
    int w, h;
    // get info about texture size
    SDL_QueryTexture(texture.get(), nullptr, nullptr, &w, &h);
    return {w, h};
}
// return the size of texture
SDL_Rect Player::getTextureRect(std::shared_ptr<SDL_Texture> texture) {
    auto [w, h] = getTextureWH(texture);
    return {0, 0, w, h};
}