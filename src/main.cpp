#include <SDL2/SDL.h>
#include <iostream>
#include "particle.h"

void updatePhysics(Particle &p1, Particle &p2, Particle &p3, float dt) {
    p1.calculateAcceleration(p2, p3);
    p1.updatePosition(dt);
    p2.updatePosition(dt);
    p3.updatePosition(dt);
}

void renderParticle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    int x = radius;
    int y = 0;
    int decision = 1 - x;

    while (y <= x) {
        // Draw horizontal lines to fill the circle
        SDL_RenderDrawLine(renderer, centerX - x, centerY + y, centerX + x, centerY + y);
        SDL_RenderDrawLine(renderer, centerX - x, centerY - y, centerX + x, centerY - y);
        SDL_RenderDrawLine(renderer, centerX - y, centerY + x, centerX + y, centerY + x);
        SDL_RenderDrawLine(renderer, centerX - y, centerY - x, centerX + y, centerY - x);

        y++;

        if (decision <= 0) {
            decision += 2 * y + 1;
        } else {
            x--;
            decision += 2 * (y - x) + 1;
        }
    }
}

const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 900;

int main(int argc, char* argv[]) {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("Particle Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Scale factor for visualization
    float scale = 1; // Adjusted scale for visibility
    // Initial positions and velocities for figure-eight pattern

    float Ax = 0.97000436;
    float Ay = -0.24308753;
    float Bx = -0.97000436;
    float By = 0.24308753;
    float Vx = 0.93240737 / 2;
    float Vy = 0.86473146 / 2;

    // Adjust initial positions for SDL window center
    float offsetX = WINDOW_WIDTH / 2;
    float offsetY = WINDOW_HEIGHT / 2;

    // Create particles for the figure-eight pattern
    Particle p1(1, Ax * scale + offsetX, Ay * scale + offsetY, Vx * scale, Vy * scale);
    Particle p2(1, Bx * scale + offsetX, By * scale + offsetY, Vx * scale, Vy * scale);
    Particle p3(1, offsetX, offsetY, -Vx * 2 * scale, -Vy * 2 * scale); // Opposite momentum for center mass

    float dt = 0.01; // Reduced time step for numerical stability

    bool quit = false;
    SDL_Event e;

    // Main loop
    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Update physics
        updatePhysics(p1, p2, p3, dt);

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw particles
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        renderParticle(renderer, static_cast<int>(p1.x), WINDOW_HEIGHT - static_cast<int>(p1.y), static_cast<int>(pow(p1.m,0.25)));
        renderParticle(renderer, static_cast<int>(p2.x), WINDOW_HEIGHT - static_cast<int>(p2.y), static_cast<int>(pow(p2.m,0.25)));
        renderParticle(renderer, static_cast<int>(p3.x), WINDOW_HEIGHT - static_cast<int>(p3.y), static_cast<int>(pow(p3.m,0.25)));

        // Update screen
        SDL_RenderPresent(renderer);

        // Delay to control frame rate
        SDL_Delay(static_cast<int>(dt * 1000)); // Adjusted delay for correct frame rate
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
