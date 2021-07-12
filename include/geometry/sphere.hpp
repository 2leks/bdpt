#pragma once
#include <memory>
#include <optional>

#include "geometry/shape.hpp"

struct Vec3;
struct Interaction;
struct Ray;

struct Sphere : Shape {
    float rad;
    std::unique_ptr<Vec3> cent;

    Sphere(float rad, const Vec3& cent);
    Sphere(Sphere& sp);
    Sphere(Sphere&& sp) = default;

    std::optional<Interaction> solve(const Ray& ray, int id) const;
    Vec3 norm(const Vec3& dir, const Vec3& at) const;
};
