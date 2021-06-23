struct Vec3;
struct Ray;
struct Scene;
struct Triangle;
struct Sphere;

namespace Path {
Vec3 radiance(const Ray& ray, Scene scene, int bounces = 0);
}  // namespace Path
