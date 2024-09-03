#include "../include/particle.h"
using namespace std;

Particle::Particle(float mass, double posX, double posY, double velX, double velY){
    m = mass;
    x = posX;
    y = posY;
    vx = velX;
    vy = velY;
    ax = ay = 0; 
}

void Particle::calculateAcceleration(Particle &p2, Particle &p3) {
    const double G = 1; // Gravitational constant
    const double epsilon = 1e-9; // Small threshold to prevent division by zero

    // Calculate distance vectors
    Vector v1_1(x - p2.x, y - p2.y); // Vector from p1 to p2
    Vector v1_2(x - p3.x, y - p3.y); // Vector from p1 to p3
    Vector v2_1(p2.x - x, p2.y - y); // Vector from p2 to p1
    Vector v2_2(p2.x - p3.x, p2.y - p3.y); // Vector from p2 to p3
    Vector v3_1(p3.x - x, p3.y - y); // Vector from p3 to p1
    Vector v3_2(p3.x - p2.x, p3.y - p2.y); // Vector from p3 to p2

    // Compute gravitational forces and accelerations

    // Check for zero distance for r1 calculation
    Vector r1 = (v1_1 / pow(v1_1.magnitude(), 3) * (-G * p2.m)) - (v1_2 / pow(v1_2.magnitude(), 3) * (G * p3.m));
    ax = r1.x;
    ay = r1.y;


    // Check for zero distance for r2 calculation

    Vector r2 = (v2_1 / pow(v2_1.magnitude(), 3) * (-G * m)) - (v2_2 / pow(v2_2.magnitude(), 3) * (G * p3.m));
    p2.ax = r2.x;
    p2.ay = r2.y;

    // Check for zero distance for r3 calculation

    Vector r3 = (v3_1 / pow(v3_1.magnitude(), 3) * (-G * m)) - (v3_2 / pow(v3_2.magnitude(), 3) * (G * p2.m));
    p3.ax = r3.x;
    p3.ay = r3.y;

    cout << "Accelerations: " << ax << " " << ay << ", " 
         << p2.ax << " " << p2.ay << ", " 
         << p3.ax << " " << p3.ay << endl;
}

void Particle::updatePosition(float dt){
    vx += ax * dt;
    vy += ay * dt;

    x += vx * dt;
    y += vy * dt;
}