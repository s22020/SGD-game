#include "levelmap.h"

LevelMap::LevelMap(int floorCount) {
    this->floorCount = floorCount;
    for (int i=0; i<floorCount; i++) {
        floorLayer.push_back({0+i*64, 416, 64, 64});
    }
}

std::vector<SDL_Rect> LevelMap::getFloorLayer() {
    return floorLayer;
}
