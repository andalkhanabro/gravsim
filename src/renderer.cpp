#include "raylib.h"
#include "renderer.h"
#include "iostream"

Renderer::Renderer(int SCREEN_WIDTH, int SCREEN_HEIGHT) {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Gravity simulator");
    SetTargetFPS(60);
    this->SCREEN_HEIGHT = SCREEN_HEIGHT; 
    this->SCREEN_WIDTH = SCREEN_WIDTH; 

}

std::pair<int, int> Renderer::coordinateTransform(double x, double y, int scale = 75) {

    int p_x = x * scale + (this->SCREEN_WIDTH)/2;
    int p_y = -y * scale + (this->SCREEN_HEIGHT)/2; 

    return {p_x, p_y}; 

}

void Renderer::draw(const World& world) {

    BeginDrawing(); 

    ClearBackground(BLACK);

    int i = 0;
    for (const Particle& p : world._all_particles) {

        std::pair<int, int> pixel_coords = this->coordinateTransform(p._x_pos, p._y_pos); 

        int p_x = pixel_coords.first;
        int p_y = pixel_coords.second;

        // std::cout << p_x << std::endl; 
        // std::cout << p_y << std::endl; 

        Color colors[] = {RED, BLUE, GREEN, YELLOW, WHITE};
        DrawCircle(p_x, p_y, 12.0f, colors[i % 5]);
        i++; 

    }

    EndDrawing(); 

}

Renderer::~Renderer() {

    CloseWindow(); 

}


