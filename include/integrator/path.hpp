#pragma once

struct Vec3;
struct Ray;
struct Scene;

namespace path {
Vec3 radiance(const Ray& ray, const Scene& scene, int bounces = 0);
}  // namespace Path
