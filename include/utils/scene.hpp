#pragma once

#include <vector>

#include "integrator/mat.hpp"
#include "integrator/shape.hpp"

struct Scene {
    std::vector<Shape> shapes{};
    std::vector<Mat> mats{};
    std::vector<int> lights{};

    void insert(Shape shape, Mat mat, bool light = false);
};
