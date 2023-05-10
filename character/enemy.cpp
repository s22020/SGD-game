#include "enemy.h"
#include "../render/render.h"
#include "../core/game.h"

Enemy::Enemy(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip)
        : Character(textureId, x, y, width, height, flip) {
    rigidBody = new RigidBody();
    animation = new Animation();
    animation->setProperties(textureId, 0, 1, 500);
}

void Enemy::draw() {
    animation->draw(transform->posX, transform->posY, width, height, flip);
}

void Enemy::clean() {
    Render::getInstance()->clean();
}

void Enemy::update(float dt) {
    rigidBody->calculateAppliedForces(dt);
    transform->translateX(rigidBody->getPosition().posX);
//    transform->translateY(rigidBody->getPosition().posY);
    animation->update();
}

SDL_RendererFlip Enemy::getFlip() {
    return flip;
}

void Enemy::setFlip(SDL_RendererFlip flip) {
    this->flip = flip;
}