#include <memory>

struct Vec3;

struct Ray {
    std::shared_ptr<Vec3> origin, direction;
    Ray(Vec3 origin, Vec3 direction);
};
