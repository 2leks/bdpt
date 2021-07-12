#pragma once
#include <memory>

#include "geometry/sphere.hpp"
#include "geometry/triangle.hpp"
#include "geometry/vec3.hpp"
#include "mats/lambertian.hpp"
#include "utils/scene.hpp"

namespace Cornell {
Scene scene() {
    Vec3 WHITE(1, 1, 1);
    Vec3 BLACK(0, 0, 0);
    Vec3 PINK(.75, .25, .75);
    Vec3 BLUE(.25, .25, .75);
    Vec3 GRAY(.75, .75, .75);
    Vec3 GREEN(.25, 1, .7);

    auto GRAY_LAMB = std::make_shared<Lambertian>(GRAY);
    auto PINK_LAMB = std::make_shared<Lambertian>(PINK);
    auto BLUE_LAMB = std::make_shared<Lambertian>(BLUE);
    auto GREEN_LAMB = std::make_shared<Lambertian>(GREEN);

    Vec3 FAR_TOP_LEFT(-1, 1, 1);
    Vec3 FAR_TOP_RIGHT(1, 1, 1);
    Vec3 FAR_BOTTOM_LEFT(-1, -1, 1);
    Vec3 FAR_BOTTOM_RIGHT(1, -1, 1);
    Vec3 CLOSE_TOP_LEFT(-1, 1, -1);
    Vec3 CLOSE_TOP_RIGHT(1, 1, -1);
    Vec3 CLOSE_BOTTOM_LEFT(-1, -1, -1);
    Vec3 CLOSE_BOTTOM_RIGHT(1, -1, -1);

    Scene scene;

    // spherical light
    scene.insert(std::make_unique<Sphere>(.25, Vec3(0, .5, 0)), std::make_unique<Lambertian>(WHITE, 1));

    // room
    scene.insert(std::make_unique<Triangle>(FAR_BOTTOM_RIGHT, CLOSE_BOTTOM_LEFT, CLOSE_BOTTOM_RIGHT), GRAY_LAMB);
    scene.insert(std::make_unique<Triangle>(FAR_BOTTOM_RIGHT, FAR_BOTTOM_LEFT, CLOSE_BOTTOM_LEFT), GRAY_LAMB);
    scene.insert(std::make_unique<Triangle>(CLOSE_BOTTOM_RIGHT, CLOSE_TOP_RIGHT, FAR_BOTTOM_RIGHT), PINK_LAMB);
    scene.insert(std::make_unique<Triangle>(FAR_BOTTOM_RIGHT, CLOSE_TOP_RIGHT, FAR_TOP_RIGHT), PINK_LAMB);
    scene.insert(std::make_unique<Triangle>(CLOSE_TOP_LEFT, CLOSE_BOTTOM_LEFT, FAR_BOTTOM_LEFT), GREEN_LAMB);
    scene.insert(std::make_unique<Triangle>(FAR_TOP_LEFT, CLOSE_TOP_LEFT, FAR_BOTTOM_LEFT), GREEN_LAMB);
    scene.insert(std::make_unique<Triangle>(CLOSE_TOP_RIGHT, CLOSE_TOP_LEFT, FAR_TOP_RIGHT), GRAY_LAMB);
    scene.insert(std::make_unique<Triangle>(CLOSE_TOP_LEFT, FAR_TOP_LEFT, FAR_TOP_RIGHT), GRAY_LAMB);
    scene.insert(std::make_unique<Triangle>(FAR_TOP_RIGHT, FAR_BOTTOM_LEFT, FAR_BOTTOM_RIGHT), GRAY_LAMB);
    scene.insert(std::make_unique<Triangle>(FAR_TOP_RIGHT, FAR_TOP_LEFT, FAR_BOTTOM_LEFT), GRAY_LAMB);

    // // tall block
    // // clang-format off
    scene.insert(std::make_unique<Triangle>(Vec3(-.52, .18, -.08), Vec3(.04, -1, .06), Vec3(-.52, -1, -.08)), BLUE_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(-.52, .18, -.08), Vec3(.04, .18, .06), Vec3(.04, -1, .06)), BLUE_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(.04, .18, .06), Vec3(-.14, -1, .64), Vec3(.04, -1, .06)), BLUE_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(.04, .18, .06), Vec3(-.14, .18, .64), Vec3(-.14, -1, .64)), BLUE_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(-.14, .18, .64), Vec3(-.7, -1, .46), Vec3(-.14, -1, .64)), BLUE_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(-.14, .18, .64), Vec3(-.7, .18, .46), Vec3(-.7, -1, .46)), BLUE_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(-.7, .18, .46), Vec3(-.52, .18, -.08), Vec3(-.7, -1, .46)), BLUE_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(-.52, .18, -.08), Vec3(-.52, -1, -.08), Vec3(-.7, -1, .46)), BLUE_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(-.7, .18, .46), Vec3(.04, .18, .06), Vec3(-.52, .18, -.08)), BLUE_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(-.7, .18, .46), Vec3(-.14, .18, .64), Vec3(.04, .18, .06)), BLUE_LAMB);
    // // clang-format on

    // // short block
    // // clang-format off
    scene.insert(std::make_unique<Triangle>(Vec3(-.04, -.4, -.58), Vec3(.54, -1, -.76), Vec3(-.04, -1, -.58)), PINK_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(-.04, -.4, -.58), Vec3(.54, -.4, -.76), Vec3(.54, -1, -.76)), PINK_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(.54, -.4, -.76), Vec3(.7, -1, -.2), Vec3(.54, -1, -.76)), PINK_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(.54, -.4, -.76), Vec3(.7, -.4, -.2), Vec3(.7, -1, -.2)), PINK_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(.7, -.4, -.2), Vec3(.14, -1, -.02), Vec3(.7, -1, -.2)), PINK_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(.7, -.4, -.2), Vec3(.14, -.4, -.02), Vec3(.14, -1, -.02)), PINK_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(.14, -.4, -.02), Vec3(-.04, -.4, -.58), Vec3(.14, -1, -.02)), PINK_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(-.04, -.4, -.58), Vec3(-.04, -1, -.58), Vec3(.14, -1, -.02)), PINK_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(.14, -.4, -.02), Vec3(.54, -.4, -.76), Vec3(-.04, -.4, -.58)), PINK_LAMB);
    scene.insert(std::make_unique<Triangle>(Vec3(.14, -.4, -.02), Vec3(.7, -.4, -.2), Vec3(.54, -.4, -.76)), PINK_LAMB);
    // // clang-format on

    return scene;
}

}  // namespace Cornell
