#include "integrator/path.hpp"

#include <iostream>
#include <optional>
#include <variant>

#include "geometry/ray.hpp"
#include "integrator/interaction.hpp"
#include "integrator/mat.hpp"
#include "utils/scene.hpp"
#include "utils/vec3.hpp"

namespace Path {

struct BSDF {
    Vec3 direction;
    Vec3 color;
    Vec3 normal;
    float f;
    float prob;
    float emission;
};

Vec3 radiance(const Ray& ray, Scene scene, int bounces) {
    if (decltype(Interaction::find(ray, scene)) action; bounces < 5 && (action = Interaction::find(ray, scene))) {
        Shape& shape = scene.shapes[action->id];
        Mat& mat = scene.mats[action->id];
        Vec3 hit = *action->point;

        BSDF bsdf = std::visit(
            [hit](const auto& shape, const auto& mat) {
                Vec3 normal = shape.normal(hit);
                Vec3 direction = mat.direction(normal);
                return BSDF{direction, *mat.color, normal, mat.bsdf(normal, direction), mat.prob, mat.emission};
            },
            shape, mat);

        Ray next(*action->point, bsdf.direction);
        return bsdf.emission + bsdf.color * bsdf.f * radiance(next, scene, bounces + 1) * (1.f / bsdf.prob);
    }

    return Vec3{};
}

}  // namespace Path
