#include "integrator/interaction.hpp"

#include "geometry/ray.hpp"
#include "utils/scene.hpp"
#include "utils/vec3.hpp"

Interaction::Interaction(int id, Vec3 point, float dist) : id(id), point(std::make_shared<Vec3>(point)), dist(dist) {}

std::optional<Interaction> Interaction::find(const Ray& ray, const Scene& scene) {
    std::optional<Interaction> action;

    for (int id = 0; id < scene.shapes.size(); id++) {
        Shape shape = scene.shapes[id];

        auto prop = std::visit(
            [ray, id](const auto& shape) -> std::optional<Interaction> {
                return shape.interact(ray, id);
            },
            shape);

        if (!action) {
            action = prop;
        } else if (prop) {
            action = prop->dist < action->dist ? prop : action;
        }
    }

    return action;
}
