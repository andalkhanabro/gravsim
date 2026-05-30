#pragma once // prevents repeated duplication of .h file due to dependency graph of .h files 
#include <iostream>

class Particle {

    // A particle with a specific position (x,y), velocity (v_x, v_y) and a mass (in kg)

    public: 

        double _x_pos, _y_pos; 
        double _v_x, _v_y; 
        double _mass; 

        // a custom constructor to make a particle 

        Particle(double x_pos, double y_pos, double v_x, double v_y, double mass);

        // to compute distance^3 between particles ||r_ij||^3 

        static double distCubed(Particle i, Particle j); 

        void updatePosition(double a_x, double a_y, double dt); // updates x_t to x_(t + dt)

        void updateVelocity(double a_x, double a_y, double dt);  // updates v_t to v_(t + dt)

};

// TODO: why must this be a free function (UNCLEAR)

std::ostream& operator<<(std::ostream& output_stream, const Particle& p); 