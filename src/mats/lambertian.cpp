#include "mats/lambertian.hpp"

#include <cmath>

#include "integrator/mat.hpp"
#include "utils/rng.hpp"
#include "utils/vec3.hpp"

Lambertian::Lambertian(const Vec3& color, float emission, float albedo, float prob)
    : Mat(color, emission, prob), albedo(albedo) {}

Vec3 Lambertian::bsdf(const Vec3& normal, const Vec3& direction) const {
    return Vec3{1, 1, 1} * albedo * PI_INV * normal.dot(direction);
}

Vec3 Lambertian::direction(const Vec3& normal) const {
    float r1 = TWO_PI * RNG::rand(0, 1);
    float r2 = RNG::rand(0, 1);
    float r2s = std::sqrt(r2);

    Vec3 u = ((std::abs(normal.x) > 0.1 ? Vec3{0, 1} : Vec3{1}).cross(normal)).norm();
    Vec3 v = normal.cross(u);
    return (u * std::cos(r1) * r2s + v * std::sin(r1) * r2s + normal * std::sqrt(1 - r2)).norm();
}
