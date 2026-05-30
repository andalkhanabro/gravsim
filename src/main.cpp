#include "world.h"
#include <iostream>
#include "particle.h"
#include "renderer.h"
#include "raylib.h"
#include <cmath>

int main() {

    std::vector<Particle> all_particles; 

    Renderer renderer(800, 800); 

    // SETTING UP THE WORLD WE WANT 

    Particle p1(5, 0.0, -1.0, 0, 1e10); 
    Particle p2(-5, 0.0, 1.0, 0, 1e10); 

    all_particles.push_back(p1);
    all_particles.push_back(p2);

    World myworld(all_particles, 0.01); 

    // PRINTING INITIAL STATES

    std::cout << "starting state of the system: " << "\n"; 

    for (int i = 0; i < myworld._all_particles.size(); i++) {

        std::cout << "Particle number: " << i << std::endl;  
        std::cout << myworld._all_particles[i]; 

    }

    std::cout << "EVOLVING IN TIME: " << "\n"; 

    // start advancing 

    while (!WindowShouldClose()) {
      myworld.advance(false);
      renderer.draw(myworld);
}

}