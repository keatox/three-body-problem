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
    if (mag != 0) {
        x /= mag;
        y /= mag;
    }
}

Vector Vector::operator-(Vector rhs){
    return Vector(x - rhs.x, y - rhs.y);;
}

Vector Vector::operator*(double mult){
    return Vector(x * mult, y * mult);;
}

Vector Vector::operator/(float q){
    if (q != 0) {
        return Vector(x / q, y / q);
    }
    return Vector(0, 0); // Handle division by zero
}