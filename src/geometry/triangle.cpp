#include "geometry/triangle.hpp"

#include <memory>
#include <optional>
#include <vector>

#include "geometry/ray.hpp"
#include "integrator/interaction.hpp"
#include "utils/constants.hpp"
#include "utils/vec3.hpp"

Triangle::Triangle(Vec3 v0, Vec3 v1, Vec3 v2)
    : v0(std::make_shared<Vec3>(v0)), v1(std::make_shared<Vec3>(v1)), v2(std::make_shared<Vec3>(v2)) {}

std::optional<Interaction> Triangle::interact(const Ray& ray, int id) const {
    Vec3 e0 = *v1 - *v0;
    Vec3 e1 = *v2 - *v0;

    Vec3 h = ray.direction->cross(e1);
    float a = e0.dot(h);

    if (a > -Const::EPS && a < Const::EPS) {
        return {};
    }

    float f = 1.f / a;
    Vec3 s = *ray.origin - *v0;
    float u = f * s.dot(h);

    if (u < 0.0 || u > 1.0) {
        return {};
    }

    Vec3 q = s.cross(e0);
    float v = f * ray.direction->dot(q);

    if (v < 0.f || u + v > 1.f) {
        return {};
    }

    float t = f * (*v2 - *v0).dot(q);
    return t > Const::EPS ? Interaction(id, *ray.origin + *ray.direction * t, t) : std::optional<Interaction>{};
}

Vec3 Triangle::normal(const Vec3& at) const {
    return (*v2 - *v0).cross(*v1 - *v0).norm();
}
