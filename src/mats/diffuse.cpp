#include "mats/diffuse.hpp"

#include <cmath>

#include "utils/constants.hpp"
#include "utils/rng.hpp"
#include "utils/vec3.hpp"

const float Diff::prob = Const::TWO_PI_INV;

Diff::Diff(const Vec3& color, float emission, float albedo)
    : color(std::make_shared<Vec3>(color)), emission(emission), albedo(albedo) {}

float Diff::bsdf(const Vec3& from, const Vec3& to) const {
    return albedo * Const::PI_INV * to.dot(from);
}

Vec3 Diff::direction(const Vec3& from) const {
    float u = RNG::rand(0, 1);
    float v = RNG::rand(0, 1);

    float z = u;
    float r = std::sqrt(std::max(0.f, 1 - z * z));
    float phi = Const::TWO_PI * v;

    Vec3 to{r * std::cos(phi), r * std::sin(phi), z};
    return from.dot(to) > 0 ? to : -1 * to;
}
