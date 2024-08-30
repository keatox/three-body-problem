#include "../include/vector.h"

Vector::Vector(float x, float y){
    this->x = x;
    this->y = y;
}

float Vector::magnitude(){
    return sqrt(x * x + y * y);
}

void Vector::normalize(){
    float mag = magnitude();
    x /= mag;
    y /= mag;
}