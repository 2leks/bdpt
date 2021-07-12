#pragma once
#include <memory>

struct Vec3;

struct Interaction {
    int id;
    float dist;
    std::unique_ptr<Vec3> hit;

    Interaction(int id, float dist, const Vec3& hit);
};
