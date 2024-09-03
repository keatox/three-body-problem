#pragma once
#ifndef THREE_BODY_PROBLEM_VECTOR
#define THREE_BODY_PROBLEM_VECTOR

#include <iostream>
#include <cmath>

class Vector{
    public:
        float x, y;

        Vector(float x, float y);
        float magnitude();
        void normalize();
        Vector operator-(Vector rhs);
        Vector operator*(double mult);
        Vector operator/(float q);
};

#endif //THREE_BODY_PROBLEM_VECTOR