#pragma once
#include <optional>

struct Interaction;
struct Ray;
struct Vec3;

struct Shape {
    virtual ~Shape() = default;

    virtual std::optional<Interaction> solve(const Ray& ray, int id) const = 0;
    virtual Vec3 norm(const Vec3& dir, const Vec3& at) const = 0;
};
