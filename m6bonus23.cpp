#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>

/**
 * Ultra-Realistic PPM Burger Generator - Animation Edition
 * Features: 60-frame generation and automatic MP4 conversion.
 */

// Simple pseudo-random function for texture grain
float noise(int x, int y) {
    int n = x + y * 57;
    n = (n << 13) ^ n;
    return (1.0f - ((n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0f);
}

void generateUltraBurger(std::string filename, float offsetX, float offsetY) {
    const int width = 600;
    const int height = 600;

    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    outFile << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            
            // --- 1. Background: Radiant Sky with Sun Glow ---
            float distToSun = std::sqrt(std::pow(x - 450, 2) + std::pow(y - 150, 2));
            float sunGlow = std::max(0.0f, 1.0f - (distToSun / 400.0f));
            
            int r = (int)(100 + 100 * sunGlow);
            int g = (int)(180 + 60 * sunGlow);
            int b = 255;

            // Character Center with offsets
            float cx = 300.0f + offsetX;
            float cy = 300.0f + offsetY;

            // --- 2. The Superhero Cape (Deep Crimson with folds) ---
            if (x < cx && x > cx - 220) {
                float capeTop = cy - 50 - (cx - x) * 0.15f;
                float capeBottom = cy + 80 + (cx - x) * 0.35f;
                capeBottom += std::sin(x * 0.04f) * 15.0f; 
                
                if (y > capeTop && y < capeBottom) {
                    float fold = 0.8f + 0.2f * std::sin(x * 0.1f + y * 0.05f);
                    r = (int)(160 * fold); g = (int)(10 * fold); b = (int)(20 * fold);
                }
            }

            // --- 3. The Burger Core Stack ---
            float lightX = 100.0f, lightY = 100.0f;
            float dx = x - lightX;
            float dy = y - lightY;
            float distToLight = std::sqrt(dx*dx + dy*dy);
            float diff = std::max(0.4f, 1.0f - (distToLight / 600.0f));
            float grain = 1.0f + 0.05f * noise(x, y);

            // TOP BUN
            float topBun = std::pow(x - cx, 2) / std::pow(120, 2) + std::pow(y - (cy - 40), 2) / std::pow(80, 2);
            if (topBun <= 1.0 && y < cy - 10) {
                r = (int)(230 * diff * grain); g = (int)(160 * diff * grain); b = (int)(80 * diff * grain);
                float specDist = std::sqrt(std::pow(x - (cx - 40), 2) + std::pow(y - (cy - 70), 2));
                if (specDist < 30) {
                    float s = (1.0f - (specDist / 30.0f)) * 50;
                    r += s; g += s; b += s;
                }
                if ((x * y + x/2) % 199 == 0) { r = 255; g = 245; b = 220; }
            }

            // LETTUCE
            float lettuceWave = std::sin(x * 0.15f) * 8.0f;
            if (y >= cy - 15 + lettuceWave && y <= cy + 5 && std::abs(x - cx) < 125) {
                float edgeFade = std::max(0.5f, 1.0f - (std::abs(x - cx) / 125.0f));
                r = (int)(60 * edgeFade); g = (int)(180 * edgeFade); b = 45;
            }

            // CHEESE
            if (y >= cy && y <= cy + 18 && std::abs(x - cx) < 118 - (y - cy)) {
                r = 255; g = 215; b = 0;
                if (y > cy + 12) { r -= 20; g -= 20; }
            }

            // PATTY
            float patty = std::pow(x - cx, 2) / std::pow(122, 2) + std::pow(y - (cy + 25), 2) / std::pow(35, 2);
            if (patty <= 1.0) {
                float meatNoise = 0.8f + 0.2f * noise(x, y);
                r = (int)(80 * diff * meatNoise); g = (int)(45 * diff * meatNoise); b = (int)(30 * meatNoise);
            }

            // BOTTOM BUN
            float botBun = std::pow(x - cx, 2) / std::pow(120, 2) + std::pow(y - (cy + 60), 2) / std::pow(55, 2);
            if (botBun <= 1.0 && y > cy + 40) {
                r = (int)(210 * diff * grain); g = (int)(140 * diff * grain); b = (int)(60 * diff * grain);
            }

            // --- 4. Hero Mask ---
            if (y > cy - 75 && y < cy - 55 && std::abs(x - cx) < 80) {
                float maskTex = 0.7f + 0.3f * std::sin(x * 0.5f);
                r = (int)(30 * maskTex); g = (int)(30 * maskTex); b = (int)(40 * maskTex);
                if (std::abs(x - (cx - 35)) < 12 || std::abs(x - (cx + 35)) < 12) {
                    if (y > cy - 70 && y < cy - 62) { r = 255; g = 255; b = 255; }
                }
            }

            outFile << std::min(255, r) << " " << std::min(255, g) << " " << std::min(255, b) << " ";
        }
        outFile << "\n";
    }
    outFile.close();
}

int main() {
    const int totalFrames = 60;
    std::cout << "Starting 60 FPS animation render..." << std::endl;

    for (int i = 0; i < totalFrames; ++i) {
        float angle = (static_cast<float>(i) / totalFrames) * 2.0f * M_PI;
        float offsetY = std::sin(angle) * 40.0f;
        float offsetX = std::cos(angle) * 10.0f;

        std::stringstream ss;
        ss << "frame_" << std::setw(2) << std::setfill('0') << i << ".ppm";
        std::string filename = ss.str();

        std::cout << "Rendering " << filename << " [" << (i + 1) << "/" << totalFrames << "]..." << std::endl;
        generateUltraBurger(filename, offsetX, offsetY);
    }

    std::cout << "\nFrames complete. Converting to MP4 using FFmpeg..." << std::endl;

    // FFmpeg Command Breakdown:
    // -framerate 60: Sets the speed to 60 frames per second
    // -i frame_%02d.ppm: Tells FFmpeg to look for files named frame_00.ppm, frame_01.ppm, etc.
    // -c:v libx264: Uses the standard H.264 video codec
    // -pix_fmt yuv420p: Ensures the video is playable on most devices (Quicktime, Web, etc.)
    // burger_animation.mp4: The output filename
    int result = system("ffmpeg -y -framerate 60 -i frame_%02d.ppm -c:v libx264 -pix_fmt yuv420p burger_animation.mp4");

    if (result == 0) {
        std::cout << "Success! Your video 'burger_animation.mp4' is ready." << std::endl;
        // Optional: Clean up the old PPM files to save space
        system("rm frame_*.ppm");
        std::cout << "Temporary PPM frames have been removed." << std::endl;
    } else {
        std::cerr << "FFmpeg error. Make sure ffmpeg is installed in your terminal." << std::endl;
    }

    return 0;
}