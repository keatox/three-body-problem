#pragma once
#ifndef THREE_BODY_PROBLEM_VECTOR
#define THREE_BODY_PROBLEM_VECTOR

#include <iostream>
#include <cmath>

class Vector{
    float x, y;

    Vector(float x, float y);
    float magnitude();
    void normalize();
};

#endif //THREE_BODY_PROBLEM_VECTOR