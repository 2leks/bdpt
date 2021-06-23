#pragma once

#include <memory>
#include <optional>

#include "integrator/shape.hpp"

struct Vec3;
struct Interaction;
struct Ray;

struct Triangle : Shape {
    std::shared_ptr<Vec3> v0, v1, v2;
    Triangle(Vec3 v0, Vec3 v1, Vec3 v2);
    std::optional<Interaction> interact(const Ray& ray, int id) const;
    Vec3 normal(const Vec3& direction, const Vec3& at) const;
};
