#include "world.h"

class Renderer {

    public:

        int SCREEN_WIDTH; 
        int SCREEN_HEIGHT; 

        // creates a graphic interface of SCREEN_WIDTH * SCREEN_HEIGHT dimensions 

        Renderer(int SCREEN_WIDTH, int SCREEN_HEIGHT); 

        // closes the window when we go out of scope 

        ~Renderer(); 

        // draws the current state of the particles on the screen 

        void draw(const World& world); 

        std::pair<int, int> coordinateTransform(double x, double y, int scale); 


};

