#include "integrator/path.hpp"

#include <memory>
#include <optional>

#include "geometry/ray.hpp"
#include "integrator/interaction.hpp"
#include "integrator/mat.hpp"
#include "utils/scene.hpp"
#include "utils/vec3.hpp"

namespace Path {

Vec3 radiance(const Ray& ray, Scene scene, int bounces) {
    if (decltype(Interaction::find(ray, scene)) action; bounces < 5 && (action = Interaction::find(ray, scene))) {
        std::shared_ptr<Shape> shape = scene.shapes[action->id];
        std::shared_ptr<Mat> mat = scene.mats[action->id];
        Vec3 hit = *action->point;

        Vec3 normal = shape->normal(*ray.direction, hit);
        Vec3 direction = mat->direction(normal);
        Vec3 f = *mat->color * mat->bsdf(normal, direction) * (1.f / mat->prob);

        Ray next(*action->point, direction);
        return mat->emission + f * radiance(next, scene, bounces + 1);
    }

    return Vec3{};
}

}  // namespace Path
