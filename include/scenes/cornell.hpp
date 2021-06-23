#include <memory>

#include "mats/diffuse.hpp"
#include "utils/scene.hpp"
#include "utils/vec3.hpp"

namespace Cornell {
Scene scene() {
    Vec3 WHITE{1, 1, 1};
    Vec3 BLACK{0, 0, 0};
    Vec3 PINK{0.75, 0.25, 0.75};
    Vec3 BLUE{0.25, 0.25, 0.75};
    Vec3 GRAY{0.75, 0.75, 0.75};
    Vec3 GREEN{0.25, 1, 0.7};

    auto GRAY_DIFF = std::make_shared<Diff>(GRAY);
    auto PINK_DIFF = std::make_shared<Diff>(PINK);
    auto BLUE_DIFF = std::make_shared<Diff>(BLUE);
    auto GREEN_DIFF = std::make_shared<Diff>(GREEN);

    Vec3 FAR_TOP_LEFT{-1, 1, 1};
    Vec3 FAR_TOP_RIGHT{1, 1, 1};
    Vec3 FAR_BOTTOM_LEFT{-1, -1, 1};
    Vec3 FAR_BOTTOM_RIGHT{1, -1, 1};

    Vec3 CLOSE_TOP_LEFT{-1, 1, -1};
    Vec3 CLOSE_TOP_RIGHT{1, 1, -1};
    Vec3 CLOSE_BOTTOM_LEFT{-1, -1, -1};
    Vec3 CLOSE_BOTTOM_RIGHT{1, -1, -1};
    Scene scene;

    // spherical light
    scene.insert(std::make_shared<Sphere>(Vec3{0, 0.5, 0}, 0.2), std::make_shared<Diff>(WHITE, 2));

    // bottom
    scene.insert(std::make_shared<Triangle>(FAR_BOTTOM_RIGHT, CLOSE_BOTTOM_LEFT, CLOSE_BOTTOM_RIGHT), GRAY_DIFF);
    scene.insert(std::make_shared<Triangle>(FAR_BOTTOM_RIGHT, FAR_BOTTOM_LEFT, CLOSE_BOTTOM_LEFT), GRAY_DIFF);
    // left
    scene.insert(std::make_shared<Triangle>(CLOSE_BOTTOM_RIGHT, CLOSE_TOP_RIGHT, FAR_BOTTOM_RIGHT), PINK_DIFF);
    scene.insert(std::make_shared<Triangle>(FAR_BOTTOM_RIGHT, CLOSE_TOP_RIGHT, FAR_TOP_RIGHT), PINK_DIFF);
    // right
    scene.insert(std::make_shared<Triangle>(CLOSE_TOP_LEFT, CLOSE_BOTTOM_LEFT, FAR_BOTTOM_LEFT), GREEN_DIFF);
    scene.insert(std::make_shared<Triangle>(FAR_TOP_LEFT, CLOSE_TOP_LEFT, FAR_BOTTOM_LEFT), GREEN_DIFF);
    // top
    scene.insert(std::make_shared<Triangle>(CLOSE_TOP_RIGHT, CLOSE_TOP_LEFT, FAR_TOP_RIGHT), GRAY_DIFF);
    scene.insert(std::make_shared<Triangle>(CLOSE_TOP_LEFT, FAR_TOP_LEFT, FAR_TOP_RIGHT), GRAY_DIFF);
    // back
    scene.insert(std::make_shared<Triangle>(FAR_TOP_RIGHT, FAR_BOTTOM_LEFT, FAR_BOTTOM_RIGHT), GRAY_DIFF);
    scene.insert(std::make_shared<Triangle>(FAR_TOP_RIGHT, FAR_TOP_LEFT, FAR_BOTTOM_LEFT), GRAY_DIFF);

    return scene;
}
}  // namespace Cornell
