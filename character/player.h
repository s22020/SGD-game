#ifndef SGD_GAME_PLAYER_H
#define SGD_GAME_PLAYER_H

#include <SDL.h>

#include <memory>

class Player {
public:
    Player() {};
    Player(SDL_Rect playerRect);
    Player(int x, int y, int w, int h);
    SDL_Rect &getPlayerRect();
    int getPlayerPosX();
    int getPlayerPosY();
    bool getFlipHorizontally();
    void setFlipHorizontally(bool flipHorizontally);


private:
    int x;
    int y;
    int w;
    int h;
    SDL_Rect playerRect;
    bool flipHorizontally = false;
//    SDL_Rect playerRect = {0, 325, 100, 100};

    void setPlayerPosX(int x);

    void setPlayerPosY(int y);


};

#endif //SGD_GAME_PLAYER_H
