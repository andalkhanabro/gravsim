#pragma once 
#include <iostream>
#include "particle.h"

class World {

    // a world containing all particles (+ their attributes) and a stepping size to run a simulation 

    public: 
        std::vector<Particle> all_particles; // a list of all particles in the world
        double dt; // step size for time 

};