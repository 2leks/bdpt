#include "geometry/triangle.hpp"

#include <memory>
#include <optional>

#include "geometry/ray.hpp"
#include "geometry/vec3.hpp"
#include "integrator/interaction.hpp"
#include "utils/constants.hpp"

Triangle::Triangle(const Vec3& v0, const Vec3& v1, const Vec3& v2)
    : v0(std::make_unique<Vec3>(v0)), v1(std::make_unique<Vec3>(v1)), v2(std::make_unique<Vec3>(v2)) {}
Triangle::Triangle(Triangle& tr) : v0(std::move(tr.v0)), v1(std::move(tr.v1)), v2(std::move(tr.v2)) {}

std::optional<Interaction> Triangle::solve(const Ray& ray, int id) const {
    Vec3 e0 = *v1 - *v0;
    Vec3 e1 = *v2 - *v0;

    Vec3 h = ray.dir->cross(e1);
    float a = e0.dot(h);

    if (a > -EPS && a < EPS) {
        return {};
    }

    float f = 1.f / a;
    Vec3 s = *ray.orig - *v0;
    float u = f * s.dot(h);

    if (u < 0.0 || u > 1.0) {
        return {};
    }

    Vec3 q = s.cross(e0);
    float v = f * ray.dir->dot(q);

    if (v < 0.f || u + v > 1.f) {
        return {};
    }

    float t = f * (*v2 - *v0).dot(q);
    return t > EPS ? Interaction(id, t, ray.move(t)) : std::optional<Interaction>();
}

Vec3 Triangle::norm(const Vec3& dir, const Vec3& at) const {
    Vec3 normal = (*v2 - *v0).cross(*v1 - *v0).norm();
    return normal.dot(dir) < 0 ? normal : -normal;
}
