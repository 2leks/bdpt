#pragma once
#include <memory>
#include <optional>

struct Vec3;
struct Interaction;
struct Scene;

struct Ray {
    std::unique_ptr<Vec3> orig, dir;

    Ray(const Vec3& orig, const Vec3& dir);
    Ray(Ray& ray);
    Ray(Ray&& ray) = default;

    Vec3 move(float dist) const;
    std::optional<Interaction> trace(const Scene& scene) const;
};
