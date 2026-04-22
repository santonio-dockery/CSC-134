#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>

/**
 * Advanced PPM Generator
 * Creates a "Deluxe Flying Burger Hero" with gradients, shading, and toppings.
 */

int main() {
    const int width = 500;
    const int height = 500;
    const std::string filename = "flying_burger.ppm";

    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Could not create file." << std::endl;
        return 1;
    }

    outFile << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            
            // --- 1. Background Gradient (Sky) ---
            // Transitions from deep blue to light blue
            float skyFactor = (float)y / height;
            int r = 100 + (int)(35 * skyFactor);
            int g = 180 + (int)(26 * skyFactor);
            int b = 255;

            // --- 2. Motion Lines (Speed) ---
            if (x < 150 && (y % 40 < 2) && x > 20 + (y % 100)) {
                r = 255; g = 255; b = 255; // White speed streaks
            }

            // Central Coordinates
            float cx = 250.0f;
            float cy = 250.0f;

            // --- 3. Superhero Cape (Flowing Red) ---
            if (x < cx && x > 80) {
                float capeTop = cy - 40 - (cx - x) * 0.2f;
                float capeBottom = cy + 60 + (cx - x) * 0.4f;
                // Add a "wave" effect to the cape using sine
                capeBottom += std::sin(x * 0.05f) * 10.0f;
                if (y > capeTop && y < capeBottom) {
                    r = 180; g = 0; b = 0;
                }
            }

            // --- 4. The Burger Stack ---
            
            // Distance calculations for shading (3D look)
            float distFromCenter = std::sqrt(std::pow(x - (cx - 20), 2) + std::pow(y - (cy - 20), 2));
            float shading = 1.0f - (distFromCenter / 150.0f);
            shading = std::max(0.6f, std::min(1.0f, shading));

            // Top Bun
            float topBun = std::pow(x - cx, 2) / std::pow(90, 2) + std::pow(y - (cy - 30), 2) / std::pow(60, 2);
            if (topBun <= 1.0 && y < cy - 10) {
                r = (int)(220 * shading); g = (int)(150 * shading); b = (int)(70 * shading);
                // Sesame Seeds
                if ((x * y + x) % 133 == 0) { r = 255; g = 240; b = 200; }
            }

            // Lettuce (Green Layer)
            if (y >= cy - 12 && y <= cy - 2 && std::abs(x - cx) < 95 + std::sin(x*0.5)*5) {
                r = 50; g = 160; b = 40;
            }

            // Cheese (Yellow Layer)
            if (y >= cy - 2 && y <= cy + 8 && std::abs(x - cx) < 90) {
                r = 255; g = 210; b = 0;
            }

            // Patty
            float patty = std::pow(x - cx, 2) / std::pow(92, 2) + std::pow(y - (cy + 15), 2) / std::pow(25, 2);
            if (patty <= 1.0) {
                r = (int)(90 * shading); g = (int)(50 * shading); b = (int)(30 * shading);
            }

            // Bottom Bun
            float botBun = std::pow(x - cx, 2) / std::pow(90, 2) + std::pow(y - (cy + 40), 2) / std::pow(40, 2);
            if (botBun <= 1.0 && y > cy + 25) {
                r = (int)(210 * shading); g = (int)(140 * shading); b = (int)(60 * shading);
            }

            // --- 5. Hero Features ---
            // Eye Mask
            if (y > cy - 55 && y < -40 + cy && std::abs(x - cx) < 60) {
                r = 20; g = 20; b = 20;
                // Eyes
                if (std::abs(x - (cx - 25)) < 8 || std::abs(x - (cx + 25)) < 8) {
                    if (y > cy - 50 && y < cy - 45) { r = 255; g = 255; b = 255; }
                }
            }

            outFile << r << " " << g << " " << b << " ";
        }
        outFile << "\n";
    }

    outFile.close();
    std::cout << "Advanced Burger Hero generated: " << filename << std::endl;
    return 0;
}