#ifndef THREE_BODY_PROBLEM_VECTOR3D
#define THREE_BODY_PROBLEM_VECTOR3D

#include <iostream>
#include <cmath>

class Vector3D{
    float x, y, z;

    public:
        Vector3D(float x, float y, float z);
        float magnitude();
        void normalize();
};

#endif //THREE_BODY_PROBLEM_VECTOR3D