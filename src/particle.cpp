#include "../include/particle.h"

Particle::Particle(float m, float posX, float posY, float posZ, float velX, float velY, float velZ){
    mass = m;
    x = posX;
    y = posY;
    z = posZ;
    vx = velX;
    vy = velY;
    vz = velZ;
    ax = ay = az = 0; 
}

