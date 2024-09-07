#pragma once
#ifndef THREE_BODY_PROBLEM_EXECUTIVE
#define THREE_BODY_PROBLEM_EXECUTIVE

#include <iostream>
#include "particle.h"

class Executive{
    public:

        Executive(); // constructor
        void updatePhysics();
        void renderParticle();
        void run();
};

#endif //THREE_BODY_PROBLEM_EXECUTIVE