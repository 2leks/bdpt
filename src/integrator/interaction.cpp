#include "integrator/interaction.hpp"

#include <memory>

#include "geometry/ray.hpp"
#include "utils/scene.hpp"
#include "utils/vec3.hpp"

Interaction::Interaction(int id, Vec3 point, float dist) : id(id), point(std::make_shared<Vec3>(point)), dist(dist) {}

std::optional<Interaction> Interaction::find(const Ray& ray, const Scene& scene) {
    std::optional<Interaction> action;

    for (int id = 0; id < scene.shapes.size(); id++) {
        std::shared_ptr<Shape> shape = scene.shapes[id];
        auto prop = shape->interact(ray, id);

          if (!action) {
            action = prop;
        } else if (prop) {
            action = prop->dist < action->dist ? prop : action;
        }
    }

    return action;
}
