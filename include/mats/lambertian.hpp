#pragma once
#include <memory>

#include "mats/mat.hpp"
#include "utils/constants.hpp"

struct Vec3;

struct Lambertian : Mat {
    Lambertian(const Vec3& color, float em = 0);
    Lambertian(Lambertian& lamb);
    Lambertian(Lambertian&& lamb) = default;

    float f(const Vec3& norm, const Vec3& dir) const;
    float prob() const;

    Vec3 dir(const Vec3& norm) const;
};
