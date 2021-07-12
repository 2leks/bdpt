#pragma once
#include <memory>
#include <optional>

#include "geometry/shape.hpp"

struct Vec3;
struct Interaction;
struct Ray;

struct Triangle : Shape {
    std::unique_ptr<Vec3> v0, v1, v2;

    Triangle(const Vec3& v0, const Vec3& v1, const Vec3& v2);
    Triangle(Triangle& tr);
    Triangle(Triangle&& tr) = default;

    std::optional<Interaction> solve(const Ray& ray, int id) const;
    Vec3 norm(const Vec3& dir, const Vec3& at) const;
};
