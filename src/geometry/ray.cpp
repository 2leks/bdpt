#include "geometry/ray.hpp"

#include <memory>

#include "utils/vec3.hpp"

Ray::Ray(Vec3 origin, Vec3 direction)
    : origin(std::make_shared<Vec3>(origin)), direction(std::make_shared<Vec3>(direction)) {}
