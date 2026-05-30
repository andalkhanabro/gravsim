#pragma once 
#include <iostream>
#include "particle.h"

class World {

    // a world containing all particles (+ their attributes) and a stepping size to run a simulation 

    public: 

        const double G = 6.674e-11; // G from physics for the world
        std::vector<Particle> _all_particles; // a list of all particles in the world
        double _dt; // step size for time 


        // a constructor 

        World(const std::vector<Particle>& all_particles, double dt); 

        // advance the bodies in _all_particles, and recompute positions and velocities for next dt

        void advance(bool printInfo); 

        // updates positions of all particles from t to t + dt
        void updatePositions(const std::vector<double>& a_x, const std::vector<double>& a_y); 
        void updateVelocities(const std::vector<double>& a_x, const std::vector<double>& a_y); 

};