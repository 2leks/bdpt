#include "mats/diffuse.hpp"
#include "utils/scene.hpp"
#include "utils/vec3.hpp"

Vec3 WHITE{1, 1, 1};
Vec3 BLACK{0, 0, 0};
Vec3 PINK{0.75, 0.25, 0.75};
Vec3 BLUE{0.25, 0.25, 0.75};
Vec3 GRAY{0.75, 0.75, 0.75};
Vec3 GREEN{0.25, 1, 0.7};

Diff GRAY_DIFF(GRAY);
Diff PINK_DIFF(PINK);
Diff BLUE_DIFF(BLUE);
Diff GREEN_DIFF(GREEN);

Vec3 FAR_TOP_LEFT{-1, 1, 1};
Vec3 FAR_TOP_RIGHT{1, 1, 1};
Vec3 FAR_BOTTOM_LEFT{-1, -1, 1};
Vec3 FAR_BOTTOM_RIGHT{1, -1, 1};

Vec3 CLOSE_TOP_LEFT{-1, 1, -1};
Vec3 CLOSE_TOP_RIGHT{1, 1, -1};
Vec3 CLOSE_BOTTOM_LEFT{-1, -1, -1};
Vec3 CLOSE_BOTTOM_RIGHT{1, -1, -1};

namespace Cornell {
Scene scene() {
    Scene scene;

    // spherical light
    scene.insert(Sphere(Vec3{0, 0.75, 0}, 0.1), Diff(WHITE, 15));

    // bottom
    scene.insert(Triangle(FAR_BOTTOM_RIGHT, CLOSE_BOTTOM_LEFT, CLOSE_BOTTOM_RIGHT), GRAY_DIFF);
    scene.insert(Triangle(FAR_BOTTOM_RIGHT, FAR_BOTTOM_LEFT, CLOSE_BOTTOM_LEFT), GRAY_DIFF);
    // left
    scene.insert(Triangle(CLOSE_BOTTOM_RIGHT, CLOSE_TOP_RIGHT, FAR_BOTTOM_RIGHT), PINK_DIFF);
    scene.insert(Triangle(FAR_BOTTOM_RIGHT, CLOSE_TOP_RIGHT, FAR_TOP_RIGHT), PINK_DIFF);
    // right
    scene.insert(Triangle(CLOSE_TOP_LEFT, CLOSE_BOTTOM_LEFT, FAR_BOTTOM_LEFT), GREEN_DIFF);
    scene.insert(Triangle(FAR_TOP_LEFT, CLOSE_TOP_LEFT, FAR_BOTTOM_LEFT), GREEN_DIFF);
    // top
    scene.insert(Triangle(CLOSE_TOP_RIGHT, CLOSE_TOP_LEFT, FAR_TOP_RIGHT), GRAY_DIFF);
    scene.insert(Triangle(CLOSE_TOP_LEFT, FAR_TOP_LEFT, FAR_TOP_RIGHT), GRAY_DIFF);
    // back
    scene.insert(Triangle(FAR_TOP_RIGHT, FAR_BOTTOM_LEFT, FAR_BOTTOM_RIGHT), GRAY_DIFF);
    scene.insert(Triangle(FAR_TOP_RIGHT, FAR_TOP_LEFT, FAR_BOTTOM_LEFT), GRAY_DIFF);

    return scene;
}
}  // namespace Cornell
