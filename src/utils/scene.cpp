#include "utils/scene.hpp"

#include "utils/vec3.hpp"

void Scene::insert(Shape shape, Mat mat, bool light) {
    shapes.emplace_back(shape);
    mats.emplace_back(mat);

    if (light) {
        lights.emplace_back(shapes.size() - 1);
    }
}
