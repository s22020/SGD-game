#ifndef SGD_GAME_RIGIDBODY_H
#define SGD_GAME_RIGIDBODY_H

#include "vector2d.h"

class RigidBody {
public:
    RigidBody();

    float getMass();
    void setMass(float mass);
    void setGravity(float gravity);
    void setForce(Vector2D force);
    void setForceX(float fx);
    void setForceY(float fy);
    void unsetForce();

    void setFriction(Vector2D fr);
    void unsetFriction();

    Vector2D getPosition();
    Vector2D getVelocity();
    Vector2D getAcceleration();

    void calculateAppliedForces(float dt);


private:
    float mass, gravity;

    Vector2D force, friction, position, velocity, acceleration;
};

#endif //SGD_GAME_RIGIDBODY_H
