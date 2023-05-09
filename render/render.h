#ifndef SGD_GAME_RENDER_H
#define SGD_GAME_RENDER_H

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <map>

class Render {
public:
    static Render* getInstance() { return render = (render != nullptr) ? render : new Render();}
    bool loadTexture(std::string id, std::string fileName);
    void drawTexture(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
    void drawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip=SDL_FLIP_NONE);
    void dropTexture(std::string id);
    void clean();

//    SDL_Rect getTextureRect(std::shared_ptr<SDL_Texture> texture);

private:
    Render() {}
    static Render* render;
    std::map<std::string, SDL_Texture*> renderMap;
//    std::pair<int, int> getTextureWidthHeight(std::shared_ptr<SDL_Texture> texture);
};

#endif //SGD_GAME_RENDER_H
