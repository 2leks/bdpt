#pragma once
#include <memory>

struct Vec3;

struct Diff {
    std::shared_ptr<Vec3> color;
    float emission = 0;
    float albedo = 1;

    Diff(const Vec3& color, float emission = 0, float albedo = 1);

    static const float prob;
    float bsdf(const Vec3& from, const Vec3& to) const;
    Vec3 direction(const Vec3& from) const;
};
