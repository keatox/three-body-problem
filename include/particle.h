#pragma once
#ifndef THREE_BODY_PROBLEM_PARTICLE
#define THREE_BODY_PROBLEM_PARTICLE

#include <iostream>
#include <cmath>
#include "vector.h"

class Particle{
    public:
        float m;      // mass
        double x, y;   // position
        double vx, vy; // velocity
        double ax, ay; // acceleration

        Particle(float mass, double posX, double posY, double velX, double velY);
        void calculateAcceleration(Particle &p2, Particle &p3);
        void updatePosition(float dt);
};

#endif //THREE_BODY_PROBLEM_PARTICLE