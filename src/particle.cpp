#include "particle.h"
#include <cmath> // to use std::pow and other mathy stuff. c++ does not have an exponentation operator 

Particle::Particle(double x_pos, double y_pos, double v_x, double v_y, double mass) {

    // creates a particle with these attributes 

    _x_pos = x_pos; 
    _y_pos = y_pos;
    _v_x = v_x;
    _v_y = v_y; 
    _mass = mass; 
}

double Particle::distCubed(Particle i, Particle j) { // static keyword only goes in .h files (hence not here)

    double dx = j._x_pos - i._x_pos; 

    double dy = j._y_pos - i._y_pos; 

    double d_cubed = std::pow((dx * dx + dy * dy), 1.5); 

    return d_cubed; 

}

void Particle::updatePosition(double a_x, double a_y, double dt) {

    double x_new; 
    double y_new; 

    double x_old = this->_x_pos;
    double y_old = this->_y_pos;

    double v_x_old = this->_v_x;
    double v_y_old = this->_v_y;

    x_new = x_old + (v_x_old) * dt + 0.5 * a_x * (dt * dt);
    y_new = y_old + (v_y_old) * dt + 0.5 * a_y * (dt * dt);

    this->_x_pos = x_new; 
    this->_y_pos = y_new; 

}


void Particle::updateVelocity(double a_x, double a_y, double dt) {

    double v_x_new; 
    double v_y_new; 

    double v_x_old = this->_v_x;
    double v_y_old = this->_v_y;

    v_x_new = v_x_old + a_x * dt; 
    v_y_new = v_y_old + a_y * dt; 

    this->_v_x = v_x_new; 
    this->_v_y = v_y_new; 

    
}

// defining a 

std::ostream& operator<<(std::ostream& output_stream, const Particle& p) {

    
    output_stream << "====================================" << std::endl; 
    output_stream << "Current x-position: " << p._x_pos << std::endl; 
    output_stream << "Current y-position: " << p._y_pos << std::endl; 
    output_stream << "Current x-velocity: " << p._v_x << std::endl; 
    output_stream << "Current y-velocity: " << p._v_y << std::endl;
    output_stream << "====================================\n" << std::endl; 

    return output_stream;

}






