#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "geometry/ray.hpp"
#include "geometry/sphere.hpp"
#include "geometry/triangle.hpp"
#include "integrator/path.hpp"
#include "mats/diffuse.hpp"
#include "scenes/cornell.hpp"
#include "utils/scene.hpp"
#include "utils/vec3.hpp"

const int h = 200;
const int w = 200;
const int f = 200;

const int samples = 128;

int main() {
    Scene scene = Cornell::scene();
    std::array<Vec3, w * h> image;
    auto camera = Vec3{0, 0, -3};

#pragma omp parallel for schedule(dynamic, 1)
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int s = 0; s < samples; s++) {
                int pixel = (h - y - 1) * w + x;
                Vec3 direction = Vec3{x - w / 2.f, y - h / 2.f, f}.norm();
                image[pixel] = image[pixel] + Path::radiance(Ray(camera, direction), scene);
            }
        }
    }

    FILE *file = std::fopen("../res.ppm", "w");
    std::fprintf(file, "P3\n%d %d\n255\n", w, h);

    for (int pixel = 0; pixel < w * h; pixel++) {
        Vec3 color = image[pixel] * (1.f / samples);
        int r = int(std::pow(std::clamp(color.x, 0.f, 1.f), 1 / 2.2) * 255 + 0.5f);
        int g = int(std::pow(std::clamp(color.y, 0.f, 1.f), 1 / 2.2) * 255 + 0.5f);
        int b = int(std::pow(std::clamp(color.z, 0.f, 1.f), 1 / 2.2) * 255 + 0.5f);
        std::fprintf(file, "%d\n%d\n%d\n", r, g, b);
    }

    return 0;
}
