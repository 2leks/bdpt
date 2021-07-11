#pragma once

#include <memory>

#include "integrator/mat.hpp"
#include "utils/constants.hpp"

struct Vec3;

struct Dielectric : Mat {
    float refraction;

    Dielectric(const Vec3& color, float emission = 0, float refraction = 1.55, float prob = 1);
    ~Dielectric() = default;

    Vec3 bsdf(const Vec3& from, const Vec3& to) const;
    Vec3 direction(const Vec3& normal) const;

   private:
    Vec3 fresnel(const Vec3& normal, const Vec3& direction) const;
};
