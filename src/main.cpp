#include "world.h"
#include <iostream>
#include "particle.h"

int main() {

    std::vector<Particle> all_particles; 

    // SETTING UP THE WORLD WE WANT 

    Particle p1(-5, 0.0, 1.0, 0.0, 1); 
    Particle p2(5, 0.0, -1.0, 0.0, 1); 

    all_particles.push_back(p1);
    all_particles.push_back(p2);

    World myworld(all_particles, 1); 

    // run a loop for 10 seconds 

    int iterations = 3; 


    // PRINTING INITIAL STATES

    std::cout << "starting state of the system: " << "\n"; 

    for (int i = 0; i < myworld._all_particles.size(); i++) {

        std::cout << "Particle number: " << i << std::endl;  
        std::cout << myworld._all_particles[i]; 

    }

    std::cout << "EVOLVING IN TIME: " << "\n"; 


    // start advancing 

    for (int i = 0; i < iterations; i++) {

        myworld.advance(true); 

    }

}


// 

Let's think thru the transform first. 



We have a Cartesian grid and some Pixel grid X,Y defined by max screen window height and width



Also, my origin is the center and has the negative part of the Cartesian plane also, but what we want is 