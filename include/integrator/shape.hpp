#pragma once

#include <optional>

struct Interaction;
struct Ray;
struct Vec3;

struct Shape {
    virtual std::optional<Interaction> interact(const Ray& ray, int id) const = 0;
    virtual Vec3 normal(const Vec3& direction, const Vec3& at) const = 0;
};
