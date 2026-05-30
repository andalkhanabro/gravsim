
#include "world.h"
#include "particle.h" // do not rely on transitive includes, its a code smell
#include <iostream>

// method implementations for World 

World::World(const std::vector<Particle>& all_particles, double dt) {
    _all_particles = all_particles; 
    _dt = dt;
}


void World::updatePositions(const std::vector<double>& a_x, const std::vector<double>& a_y) {

    for (int i = 0; i < this->_all_particles.size(); i++) {

        Particle& p_i = this->_all_particles[i];  // reference is necessary here to bind p_i to the SAME particle as the one read
        p_i.updatePosition(a_x[i], a_y[i], World::_dt);

    }
}

void World::updateVelocities(const std::vector<double>& a_x, const std::vector<double>& a_y) {


    for (int i = 0; i < this->_all_particles.size(); i++) {

        Particle& p_i = this->_all_particles[i]; 
        p_i.updateVelocity(a_x[i], a_y[i], World::_dt);

    }

}

void World::advance(bool printInfo) {

    // advances the state of all particles from t to t+dt 

    int N = _all_particles.size(); 

    std::vector<double> a_x(N, 0.0); // an array to store x accelerations for all particles 
    std::vector<double> a_y(N, 0.0); // an array to store x accelerations for all particles 

    for (int i = 0; i < N; i++) {

        Particle p_i = _all_particles[i]; 

        for (int j = i + 1; j < N; j++) {

            Particle p_j = _all_particles[j]; 

            double d_cubed = Particle::distCubed(p_i, p_j); // d^3 
            double x_ji = p_j._x_pos - p_i._x_pos;  // delta x
            double y_ji = p_j._y_pos - p_i._y_pos;  // delta y 

            double a_x_i = ((World::G * p_j._mass) / d_cubed) * x_ji; 
            double a_y_i = ((World::G * p_j._mass) / d_cubed) * y_ji;

            a_x[i] = a_x[i] + a_x_i; // contribution to a_x from jth particle onto i
            a_y[i] = a_y[i] + a_y_i; // contribution to a_y from jth particle onto i

            // for the jth particle, a_x and a_y flipped due to N3 Law, so no need to recompute. [OPTIMIZATION]
            // we update simultaneously 

            a_x[j] -= a_x_i; 
            a_y[j] -= a_y_i; 

        }

    }

    // update at end, since we need the old state of the ith particle for effect on some other kth particle
    // so cannot modify inside the loop 

    this->updatePositions(a_x, a_y); 
    this->updateVelocities(a_x, a_y); 

    for (int i = 0; i < N; i++) {

        std::cout << "Particle number: " << i << std::endl;  
        std::cout << _all_particles[i]; 

    }

}
