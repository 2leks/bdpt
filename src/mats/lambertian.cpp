#include "mats/lambertian.hpp"

#include <cmath>
#include <memory>

#include "geometry/vec3.hpp"
#include "mats/mat.hpp"
#include "utils/constants.hpp"
#include "utils/rng.hpp"

Lambertian::Lambertian(const Vec3& color, float em) : Mat(color, em) {}
Lambertian::Lambertian(Lambertian& lamb) : Mat(lamb) {}

float Lambertian::f(const Vec3& norm, const Vec3& dir) const {
    return PI_INV * norm.dot(dir);
}

float Lambertian::prob() const {
    return TWO_PI_INV;
}

Vec3 Lambertian::dir(const Vec3& norm) const {
    float r1 = TWO_PI * rng::gen(0, 1);
    float r2 = rng::gen(0, 1);
    float r2s = std::sqrt(r2);

    Vec3 u = ((std::abs(norm.x) > 0.1 ? Vec3(0, 1, 0) : Vec3(1, 0, 0)).cross(norm)).norm();
    Vec3 v = norm.cross(u);
    return (u * std::cos(r1) * r2s + v * std::sin(r1) * r2s + norm * std::sqrt(1 - r2)).norm();
}
