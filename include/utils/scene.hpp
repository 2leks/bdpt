#pragma once
#include <memory>
#include <vector>

#include "geometry/shape.hpp"
#include "geometry/vec3.hpp"
#include "mats/mat.hpp"

struct Scene {
    std::vector<std::unique_ptr<Shape>> shapes;
    std::vector<std::shared_ptr<Mat>> mats;

    void insert(std::unique_ptr<Shape> shape, std::shared_ptr<Mat> mat);
};
