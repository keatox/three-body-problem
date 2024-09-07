#pragma once
#ifndef THREE_BODY_PROBLEM_VECTOR
#define THREE_BODY_PROBLEM_VECTOR

#include <iostream>
#include <cmath>

class Vector{
    public:
        float x, y;  // vector components

        Vector(float x, float y);      // constructor
        float magnitude();             // calculates magnitude of vector
        void normalize();              // normalizes vector
        Vector operator-(Vector rhs);  // operator overload for subtraction
        Vector operator*(double mult); // operator overload for multiplication
        Vector operator/(float q);     // operator overload for division
};

#endif //THREE_BODY_PROBLEM_VECTOR