#include "integrator/path.hpp"

#include <memory>
#include <optional>

#include "geometry/ray.hpp"
#include "geometry/vec3.hpp"
#include "integrator/interaction.hpp"
#include "mats/mat.hpp"
#include "utils/scene.hpp"

namespace path {

Vec3 radiance(const Ray& ray, const Scene& scene, int bounces) {
    if (decltype(ray.trace(scene)) action; bounces < 5 && (action = ray.trace(scene))) {
        std::shared_ptr<Mat> mat = scene.mats[action->id];
        Vec3 hit = *action->hit;

        Vec3 norm = scene.shapes[action->id]->norm(*ray.dir, hit);
        Vec3 dir = mat->dir(norm);
        Vec3 color = *mat->color;

        Vec3 f = color * mat->f(norm, dir) * (1.f / mat->prob());
        Ray next(*action->hit, dir);
        return mat->em + f * radiance(next, scene, bounces + 1);
    }

    return Vec3(0, 0, 0);
}

}  // namespace path
