#include <variant>

#include "geometry/sphere.hpp"
#include "geometry/triangle.hpp"

using Shape = std::variant<Sphere, Triangle>;
