#ifndef SGD_GAME_COLLIDER_H
#define SGD_GAME_COLLIDER_H

#include <SDL.h>

class Collider {
public:
    inline SDL_Rect getBox() { return box; }
    inline void setMargin(int x, int y, int w, int  h) { margin = {x, y, w, h}; }

    void setBox(int x, int y, int w, int h) {
        box = {
                x - margin.x,
                y - margin.y,
                w - margin.w,
                h - margin.h
        };
    }

private:
    SDL_Rect box;
    SDL_Rect margin;
};

#endif //SGD_GAME_COLLIDER_H
