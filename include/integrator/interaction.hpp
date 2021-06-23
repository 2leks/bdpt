#include <limits>
#include <memory>
#include <optional>

struct Vec3;
struct Ray;
struct Scene;

struct Interaction {
    int id;
    std::shared_ptr<Vec3> point;
    float dist = std::numeric_limits<float>::infinity();
    Interaction(int id, Vec3 point, float dist);
    static std::optional<Interaction> find(const Ray& ray, const Scene& scene);
};
