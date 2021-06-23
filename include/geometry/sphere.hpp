#pragma once

#include <memory>
#include <optional>

#include "integrator/shape.hpp"

struct Vec3;
struct Interaction;
struct Ray;

struct Sphere : Shape {
    std::shared_ptr<Vec3> center;
    float radius;
    Sphere(Vec3 center, float radius);
    std::optional<Interaction> interact(const Ray& ray, int id) const;
    Vec3 normal(const Vec3& direction, const Vec3& at) const;
};
