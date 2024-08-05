#include "../include/vector3D.h"

using namespace std;

Vector3D::Vector3D(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3D::magnitude(){
    return sqrt(x * x + y * y + z * z);
}

void Vector3D::normalize(){
    float mag = magnitude();
    x /= mag;
    y /= mag;
    z /= mag;
}

int main(){
    Vector3D vec = Vector3D(4,5,0);
    float x = vec.magnitude();
    cout << x << endl;
}