#ifndef SGD_GAME_COLLISIONHANDLER_H
#define SGD_GAME_COLLISIONHANDLER_H

#include <SDL.h>
#include "../render/levelmap.h"

class CollisionHandler {
public:
    bool checkCollision(SDL_Rect a, SDL_Rect b);
//    bool mapCollision(SDL_Rect a);

    inline static CollisionHandler* getInstance(){ return collisionHandler = (collisionHandler != nullptr) ? collisionHandler : new CollisionHandler; }


private:
    static CollisionHandler* collisionHandler;
    CollisionHandler();
//    LevelMap* levelMap;
    std::vector<SDL_Rect> collisionLayer;

};

#endif //SGD_GAME_COLLISIONHANDLER_H
