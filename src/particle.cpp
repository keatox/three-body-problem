#include "../include/particle.h"
using namespace std;

// constructor 
Particle::Particle(float mass, double posX, double posY, double velX, double velY){
    m = mass;
    x = posX;
    y = posY;
    vx = velX;
    vy = velY;
    ax = ay = 0; 
}

// assigns acceleration based on location of three bodies in space
void Particle::calculateAcceleration(Particle &p2, Particle &p3) {
    const double G = 1;          // gravitational constant

    // distance vectors between every combination of particle
    Vector v1_1(x - p2.x, y - p2.y);       // vector from p1 to p2
    Vector v1_2(x - p3.x, y - p3.y);       // vector from p1 to p3
    Vector v2_1(p2.x - x, p2.y - y);       // vector from p2 to p1
    Vector v2_2(p2.x - p3.x, p2.y - p3.y); // vector from p2 to p3
    Vector v3_1(p3.x - x, p3.y - y);       // vector from p3 to p1
    Vector v3_2(p3.x - p2.x, p3.y - p2.y); // vector from p3 to p2

    // compute acceleration for p1
    Vector r1 = (v1_1 / pow(v1_1.magnitude(), 3) * (-G * p2.m)) - (v1_2 / pow(v1_2.magnitude(), 3) * (G * p3.m));
    ax = r1.x;
    ay = r1.y;

    // compute acceleration for p2
    Vector r2 = (v2_1 / pow(v2_1.magnitude(), 3) * (-G * m)) - (v2_2 / pow(v2_2.magnitude(), 3) * (G * p3.m));
    p2.ax = r2.x;
    p2.ay = r2.y;

    // compute acceleration for p3
    Vector r3 = (v3_1 / pow(v3_1.magnitude(), 3) * (-G * m)) - (v3_2 / pow(v3_2.magnitude(), 3) * (G * p2.m));
    p3.ax = r3.x;
    p3.ay = r3.y;
}

// updates particle position based on given time step and acceleration
void Particle::updatePosition(float dt){
    vx += ax * dt;
    vy += ay * dt;

    x += vx * dt;
    y += vy * dt;
}