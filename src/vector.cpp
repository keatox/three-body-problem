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

Vector Vector::operator-(Vector rhs){
    Vector v(x - rhs.x, y - rhs.y);
    return v;
}

Vector Vector::operator*(double mult){
    Vector v(x * mult, y * mult);
    return v;
}

Vector Vector::operator/(float q){
    Vector v(x/q, y/q);
    return v;
}