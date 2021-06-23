#include "mats/diffuse.hpp"

#include <cmath>

#include "integrator/mat.hpp"
#include "utils/rng.hpp"
#include "utils/vec3.hpp"

Diff::Diff(const Vec3& color, float emission, float albedo, float prob) : Mat(color, emission, prob), albedo(albedo) {}

float Diff::bsdf(const Vec3& from, const Vec3& to) const {
    return albedo * PI_INV * to.dot(from);
}

Vec3 Diff::direction(const Vec3& normal) const {
    float r1 = TWO_PI * RNG::rand(0, 1);
    float r2 = RNG::rand(0, 1);
    float r2s = std::sqrt(r2);

    Vec3 u = ((std::abs(normal.x) > 0.1 ? Vec3{0, 1} : Vec3{1}).cross(normal)).norm();
    Vec3 v = normal.cross(u);
    return (u * std::cos(r1) * r2s + v * std::sin(r1) * r2s + normal * std::sqrt(1 - r2)).norm();
}
