#pragma once

#include <memory>
#include <vector>

#include "integrator/mat.hpp"
#include "integrator/shape.hpp"

struct Scene {
    std::vector<std::shared_ptr<Shape>> shapes;
    std::vector<std::shared_ptr<Mat>> mats;
    std::vector<int> lights;

    void insert(std::shared_ptr<Shape> shape, std::shared_ptr<Mat> mat, bool light = false);
};
