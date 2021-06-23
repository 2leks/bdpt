#include "integrator/mat.hpp"

#include <memory>

#include "utils/vec3.hpp"

Mat::Mat(Vec3 color, float emission, float prob) : color(std::make_shared<Vec3>(color)), emission(emission), prob(prob) {}
