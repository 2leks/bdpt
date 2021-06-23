#pragma once

#include <memory>

#include "integrator/mat.hpp"
#include "utils/constants.hpp"

struct Vec3;

struct Diff : Mat {
    float albedo = 1;

    Diff(const Vec3& color, float emission = 0, float albedo = 1, float prob = TWO_PI_INV);
    ~Diff() = default;

    float bsdf(const Vec3& from, const Vec3& to) const;
    Vec3 direction(const Vec3& normal) const;
};
