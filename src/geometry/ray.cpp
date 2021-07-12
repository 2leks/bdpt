#include "geometry/ray.hpp"

#include <memory>
#include <optional>

#include "geometry/vec3.hpp"
#include "integrator/interaction.hpp"
#include "utils/scene.hpp"

Ray::Ray(const Vec3& orig, const Vec3& dir) : orig(std::make_unique<Vec3>(orig)), dir(std::make_unique<Vec3>(dir)) {}
Ray::Ray(Ray& ray) : orig(std::move(ray.orig)), dir(std::move(ray.dir)) {}

Vec3 Ray::move(float dist) const {
    return *orig + dist * *dir;
}

std::optional<Interaction> Ray::trace(const Scene& scene) const {
    std::optional<Interaction> action;
    int id = 0;

    for (auto& shape : scene.shapes) {
        auto prop = shape->solve(*this, id++);
        if (!action || prop && prop->dist < action->dist) {
            action = std::move(prop);
        }
    }

    return action;
}
