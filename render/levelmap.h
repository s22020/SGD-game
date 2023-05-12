#ifndef SGD_GAME_LEVELMAP_H
#define SGD_GAME_LEVELMAP_H

#include <vector>
#include <SDL.h>

class LevelMap {
public:
    LevelMap(int floorCount);
    std::vector<SDL_Rect> getFloorLayer();
    int getFloorCount();

private:
    std::vector<SDL_Rect> floorLayer;
    int floorCount;
};

#endif //SGD_GAME_LEVELMAP_H
