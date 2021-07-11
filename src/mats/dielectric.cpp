#include "mats/dielectric.hpp"

#include <cmath>

#include "integrator/mat.hpp"
#include "utils/rng.hpp"
#include "utils/vec3.hpp"

Dielectric::Dielectric(const Vec3& color, float emission, float refraction, float prob)
    : Mat(color, emission, prob), refraction(refraction) {}

Vec3 Dielectric::fresnel(const Vec3& normal, const Vec3& direction) const {
    return direction - 2 * normal.dot(direction) * normal;
}

Vec3 Dielectric::bsdf(const Vec3& normal, const Vec3& direction) const {
    return fresnel(normal, direction);
}

Vec3 Dielectric::direction(const Vec3& normal) const {
    return Vec3{};
}
