#include "../include/vector.h"

// constructor
Vector::Vector(float x, float y){
    this->x = x;
    this->y = y;
}

// returns magnitude of vector
float Vector::magnitude(){
    return sqrt(x * x + y * y);
}

// normalizes vector
void Vector::normalize(){
    float mag = magnitude();
    if (mag != 0) {
        x /= mag;
        y /= mag;
    }
}

// overload for subtraction between two vectors
Vector Vector::operator-(Vector rhs){
    return Vector(x - rhs.x, y - rhs.y);;
}

// overload for multiplication between vector and double
Vector Vector::operator*(double mult){
    return Vector(x * mult, y * mult);;
}

// overload for division between vector and float
Vector Vector::operator/(float q){
    if (q != 0) {
        return Vector(x / q, y / q);
    }
    return Vector(0, 0); // handle division by zero
}