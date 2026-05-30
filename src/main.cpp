#include "world.h"
#include <iostream>
#include "particle.h"
#include "renderer.h"
#include "raylib.h"
#include <cmath>

int main() {

    std::vector<Particle> all_particles; 

    Renderer renderer(1200, 1200); 

    // SETTING UP THE WORLD WE WANT 

    Particle p1(5, 0.0, -1.0, 0, 1e8); 
    Particle p2(-5, 0.0, 1.0, 0, 1e10); 
    Particle p3(0.0, 6.0, 0.0, -1.0, 1e9); 
    Particle p4(0.0, -1.0, 0.0, 2.0, 1e7); 

    all_particles.push_back(p1);
    all_particles.push_back(p2);
    all_particles.push_back(p3);
    all_particles.push_back(p4);

    World myworld(all_particles, 0.00001); 

    // PRINTING INITIAL STATES

    std::cout << "starting state of the system: " << "\n"; 

    for (int i = 0; i < myworld._all_particles.size(); i++) {

        std::cout << "Particle number: " << i << std::endl;  
        std::cout << myworld._all_particles[i]; 

    }

    std::cout << "EVOLVING IN TIME: " << "\n"; 

    // start advancing 

    int steps = 0;
    int max_steps = 6000; 
    while (!WindowShouldClose() && steps < max_steps) {

    for (int i = 0; i < 1000; i++) {
    myworld.advance(true); // advancing MANY times so that actual sim time that passes is alot 
    }
      renderer.draw(myworld);
      steps++; 
}

}