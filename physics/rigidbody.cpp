#include "rigidbody.h"

RigidBody::RigidBody() {
    mass = 1.0f;
    gravity = 9.81f;
}

void RigidBody::calculateAppliedForces(float dt) {
    acceleration.posX = (force.posX + friction.posX) / mass;
    acceleration.posY = gravity + force.posY / mass;
//    velocity = acceleration * dt;
//    velocity = acceleration;
//    position = velocity * dt;
//    position = velocity;
    position = acceleration;
}

float RigidBody::getMass() {
    return mass;
}

void RigidBody::setMass(float mass) {
    this->mass = mass;
}

void RigidBody::setGravity(float gravity) {
    this->gravity = gravity;
}

void RigidBody::setForce(Vector2D force) {
    this->force = force;
}

void RigidBody::setForceX(float fx) {
    this->force.posX = fx;
}

void RigidBody::setForceY(float fy) {
    this->force.posY = fy;
}

void RigidBody::unsetForce() {
    this->force = Vector2D(0, 0);
}

void RigidBody::setFriction(Vector2D fr) {
    this->friction = fr;
}

void RigidBody::unsetFriction() {
    this->friction = Vector2D(0, 0);
}

Vector2D RigidBody::getPosition() {
    return position;
}

Vector2D RigidBody::getVelocity() {
    return velocity;
}

Vector2D RigidBody::getAcceleration() {
    return acceleration;
}