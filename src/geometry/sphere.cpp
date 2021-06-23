#include "geometry/sphere.hpp"

#include <cmath>
#include <memory>
#include <optional>

#include "geometry/ray.hpp"
#include "integrator/interaction.hpp"
#include "utils/constants.hpp"
#include "utils/vec3.hpp"

Sphere::Sphere(Vec3 center, float radius) : center(std::make_shared<Vec3>(center)), radius(radius) {}

std::optional<Interaction> Sphere::interact(const Ray& ray, int id) const {
    Vec3 v = *center - *ray.origin;
    float b = v.dot(*ray.direction);
    float d = std::sqrt(b * b - v.dot(v) + radius * radius);

    float tn, t = (tn = b - d) > Const::EPS ? tn : (tn = (b + d)) > Const::EPS ? tn : -1;
    return t > 0 ? Interaction(id, *ray.origin + *ray.direction * t, t) : std::optional<Interaction>{};
}

Vec3 Sphere::normal(const Vec3& at) const {
    return (at - *center).norm();
}
