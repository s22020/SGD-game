#ifndef SGD_GAME_TRANSFORM_H
#define SGD_GAME_TRANSFORM_H

#include "vector2d.h"

class Transform {
public:
    float posX, posY;

    Transform(float x=0, float y=0) : posX(x), posY(y) {}

    // function that is moving objects in game
    inline void translateX(float x) { posX += x; }
    inline void translateY(float y) { posY += y; }
    inline void translate(Vector2D v) { posX += v.posX, posY += v.posY; }

    void log(std::string msg) {
        std::cout << msg << "(TposX TposY) = (" << posX << " " << posY << ")" << std::endl;
    }

private:
};

#endif //SGD_GAME_TRANSFORM_H
