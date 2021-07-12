#pragma once
#include <memory>

#include "mats/mat.hpp"

struct Vec3;

struct Dielectric : Mat {
    float ior;

    Dielectric(const Vec3& color, float ior = 1.55, float em = 0);
    Dielectric(Dielectric& diel);
    Dielectric(Dielectric&& diel) = default;

    float f(const Vec3& from, const Vec3& to) const;
    float prob() const;

    Vec3 dir(const Vec3& norm) const;
};
