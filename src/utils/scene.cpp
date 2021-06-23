#include "utils/scene.hpp"

#include "utils/vec3.hpp"

void Scene::insert(std::shared_ptr<Shape> shape, std::shared_ptr<Mat> mat, bool light) {
    shapes.emplace_back(shape);
    mats.emplace_back(mat);

    if (light) {
        lights.emplace_back(shapes.size() - 1);
    }
}
