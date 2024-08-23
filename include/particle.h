#pragma once
#ifndef THREE_BODY_PROBLEM_PARTICLE
#define THREE_BODY_PROBLEM_PARTICLE

#include <iostream>
#include <cmath>

// Particle class definition
class Particle {
    public:
        float mass;
        float x, y, z; // Position
        float vx, vy, vz; // Velocity
        float ax, ay, az; // Acceleration

        Particle(float m, float posX, float posY, float posZ, float velX, float velY, float velZ);
    };

#endif //THREE_BODY_PROBLEM_PARTICLE