#include "mats/dielectric.hpp"

#include <memory>

#include "geometry/vec3.hpp"
#include "mats/mat.hpp"
#include "utils/constants.hpp"

Dielectric::Dielectric(const Vec3& color, float ior, float em) : Mat(color, em), ior(ior) {}
Dielectric::Dielectric(Dielectric& diel) : Mat(diel), ior(diel.ior) {}

float Dielectric::f(const Vec3& from, const Vec3& to) const {
    return 1;
}

float Dielectric::prob() const {
    return 1;
}

Vec3 Dielectric::dir(const Vec3& norm) const {
    return Vec3(1, 1, 1);
}
