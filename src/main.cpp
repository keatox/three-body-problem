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

    // Create particles for the figure-eight pattern
    Particle p1(1, 700.97000436, 449.75691247, 0.93240737 / 2, 0.86473146 / 2);
    Particle p2(1, 699.02999564, 450.24308753, 0.93240737 / 2 , 0.86473146 / 2);
    Particle p3(1,700,450, -0.93240737, -0.86473146); // Opposite momentum for center mass

    float dt = 0.01; // Reduced time step for numerical stability

    bool quit = false;
    SDL_Event e;

    float scale = 200;
    const float zoomFactor = 1.1f; // Factor for zooming in and out

    // Main loop
    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_MOUSEWHEEL) {
                // Zoom in or out based on the mouse wheel
                if (e.wheel.y > 0) { // Scroll up, zoom in
                    scale *= zoomFactor;
                } else if (e.wheel.y < 0) { // Scroll down, zoom out
                    scale /= zoomFactor;
                }
            }
        }

        // Update physics
        updatePhysics(p1, p2, p3, dt);

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw particles
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        renderParticle(renderer, static_cast<int>((p1.x - WINDOW_WIDTH/2) * scale + WINDOW_WIDTH/2), WINDOW_HEIGHT - static_cast<int>((p1.y - WINDOW_HEIGHT/2) * scale + WINDOW_HEIGHT/2), static_cast<int>(3));
        renderParticle(renderer, static_cast<int>((p2.x - WINDOW_WIDTH/2) * scale + WINDOW_WIDTH/2), WINDOW_HEIGHT - static_cast<int>((p2.y - WINDOW_HEIGHT/2) * scale + WINDOW_HEIGHT/2), static_cast<int>(3));
        renderParticle(renderer, static_cast<int>((p3.x - WINDOW_WIDTH/2) * scale + WINDOW_WIDTH/2), WINDOW_HEIGHT - static_cast<int>((p3.y - WINDOW_HEIGHT/2) * scale + WINDOW_HEIGHT/2), static_cast<int>(3));

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
