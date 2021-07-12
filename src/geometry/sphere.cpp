#include "geometry/sphere.hpp"

#include <cmath>
#include <memory>
#include <optional>

#include "geometry/ray.hpp"
#include "geometry/vec3.hpp"
#include "integrator/interaction.hpp"
#include "utils/constants.hpp"

Sphere::Sphere(float rad, const Vec3& cent) : rad(rad), cent(std::make_unique<Vec3>(cent)) {}
Sphere::Sphere(Sphere& sp) : rad(sp.rad), cent(std::move(sp.cent)) {}

std::optional<Interaction> Sphere::solve(const Ray& ray, int id) const {
    Vec3 v = *cent - *ray.orig;
    float b = v.dot(*ray.dir);
    float d = std::sqrt(b * b - v.dot(v) + rad * rad);

    float tn, t = (tn = b - d) > EPS ? tn : (tn = (b + d)) > EPS ? tn : -1;
    return t > EPS ? Interaction(id, t, ray.move(t)) : std::optional<Interaction>();
}

Vec3 Sphere::norm(const Vec3& dir, const Vec3& at) const {
    Vec3 normal = (at - *cent).norm();
    return normal.dot(dir) < 0 ? normal : -normal;
}
