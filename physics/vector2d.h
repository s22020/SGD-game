#ifndef SGD_GAME_VECTOR2D_H
#define SGD_GAME_VECTOR2D_H

#include <iostream>

class Vector2D {
public:
    float posX, posY;

    Vector2D(float x=0, float y=0) : posX(x), posY(y) {}
    // overriding addition of two vectors
    inline Vector2D operator+(const Vector2D& v2) {
        return Vector2D(posX + v2.posX, posY + v2.posY);
    }

    // overriding subtraction of two vectors
    inline Vector2D operator-(const Vector2D& v2) {
        return Vector2D(posX - v2.posX, posY - v2.posY);
    }

    // overriding multiplication of vector by scalar
    inline Vector2D operator+(const float scalar) {
        return Vector2D(posX * scalar, posY * scalar);
    }

    void log(std::string msg) {
        std::cout << msg << "(vPosX vPosY) = (" << posX << " " << posY << ")" << std::endl;
    }

private:
};

#endif //SGD_GAME_VECTOR2D_H
