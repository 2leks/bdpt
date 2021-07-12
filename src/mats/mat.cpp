#include "mats/mat.hpp"

#include <memory>

#include "geometry/vec3.hpp"

Mat::Mat(const Vec3& color, float em) : color(std::make_unique<Vec3>(color)), em(em) {}
Mat::Mat(Mat& mat) : color(std::move(mat.color)), em(mat.em) {}
