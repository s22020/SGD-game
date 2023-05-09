#include "player.h"

Player::Player(SDL_Rect playerRect) {
    this->playerRect = playerRect;
}

Player::Player(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    playerRect = {x, y, w, h};
}

SDL_Rect &Player::getPlayerRect() {
    return playerRect;
}

int Player::getPlayerPosX() {
    return x;
}

int Player::getPlayerPosY() {
    return y;
}

bool Player::getFlipHorizontally() {
    return flipHorizontally;
}

void Player::setPlayerPosX(int x) {
    this->x = x;
}

void Player::setPlayerPosY(int y) {
    this->y = y;
}

void Player::setFlipHorizontally(bool flipHorizontally) {
    this->flipHorizontally = flipHorizontally;
}