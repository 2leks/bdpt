#pragma once
#include <memory>

struct Vec3;

struct Mat {
    float em = 0;
    std::unique_ptr<Vec3> color;

    Mat(const Vec3& color, float em);
    Mat(Mat& mat);
    Mat(Mat&& mat) = default;
    virtual ~Mat() = default;

    virtual float f(const Vec3& from, const Vec3& to) const = 0;
    virtual float prob() const = 0;

    virtual Vec3 dir(const Vec3& norm) const = 0;
};
