#include "utils/scene.hpp"

#include <memory>
#include <vector>

void Scene::insert(std::unique_ptr<Shape> shape, std::shared_ptr<Mat> mat) {
    shapes.emplace_back(std::move(shape));
    mats.emplace_back(mat);
}
