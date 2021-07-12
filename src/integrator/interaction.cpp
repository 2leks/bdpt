#include "integrator/interaction.hpp"

#include <memory>

#include "geometry/vec3.hpp"

Interaction::Interaction(int id, float dist, const Vec3& hit) : id(id), dist(dist), hit(std::make_unique<Vec3>(hit)) {}
