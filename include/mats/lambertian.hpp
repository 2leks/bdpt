#pragma once

#include <memory>

#include "integrator/mat.hpp"
#include "utils/constants.hpp"

struct Vec3;

struct Lambertian : Mat {
    float albedo;

    Lambertian(const Vec3& color, float emission = 0, float albedo = 1, float prob = TWO_PI_INV);
    ~Lambertian() = default;

    Vec3 bsdf(const Vec3& normal, const Vec3& direction) const;
    Vec3 direction(const Vec3& normal) const;
};
