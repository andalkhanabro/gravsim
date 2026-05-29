#pragma once // prevents repeated duplication of .h file due to dependency graph of .h files 

class Particle {

    // A particle with a specific position (x,y), velocity (v_x, v_y) and a mass (in kg)

    public: 

        double x_pos, y_pos; 
        double v_x, v_y; 
        double mass; 

};



