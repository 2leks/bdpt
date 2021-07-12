#include "utils/rng.hpp"

#include <random>

namespace rng {
float gen(float min, float max) {
    static std::default_random_engine gen;
    static std::uniform_real_distribution<float> distr(min, max);
    return distr(gen);
}
}  // namespace rng
