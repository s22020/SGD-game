#include "collisionhandler.h"
#include "../core/game.h"

CollisionHandler* CollisionHandler::collisionHandler = nullptr;

CollisionHandler::CollisionHandler() {
    collisionLayer = Game::getInstance()->levelMap->getFloorLayer();
}

bool CollisionHandler::checkCollision(SDL_Rect a, SDL_Rect b) {
    // x postaci jest mniejsze od x + dlugosc tekstury i
    // czyli np 0 i 0 + 64
    // i jak x postaci + dlugosc tekstury jest wieksza od x tekstury
    // czyli np. 0 + 64 jest wieksze od 0
    bool xOverlap = (a.x < b.x + b.w ) && (a.x + a.w > b.x);
    bool yOverlap = (a.y < b.y + b.h ) && (a.y + a.h > b.y);
    return (xOverlap && yOverlap);
}

//// a to postać
//// muszę obliczyć pozycję całego rectangla
//bool CollisionHandler::mapCollision(SDL_Rect a) {
//
//    int leftFloorEdge = a.x;
//    int rightFloorEdge = a.x + a.w;
//    int topFloorEdge = a.y;
//    int bottomFloorEdge = a.y + a.h;
//
//
//
//}