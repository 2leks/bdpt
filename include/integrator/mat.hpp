#pragma once 

#include <memory>

struct Vec3;

struct Mat {
    float emission = 0;
    float prob;
    std::shared_ptr<Vec3> color;

    Mat(Vec3 color, float emission, float prob);
    ~Mat() = default;

    virtual float bsdf(const Vec3& from, const Vec3& to) const = 0;
    virtual Vec3 direction(const Vec3& normal) const = 0;
};
