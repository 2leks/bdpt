#include "utils/vec3.hpp"

#include <cmath>

Vec3 Vec3::operator+(float rhs) const {
    return Vec3{x + rhs, y + rhs, z + rhs};
}

Vec3 Vec3::operator*(float rhs) const {
    return Vec3{x * rhs, y * rhs, z * rhs};
}

Vec3 Vec3::operator+(Vec3 const& rhs) const {
    return Vec3{x + rhs.x, y + rhs.y, z + rhs.z};
}

Vec3 Vec3::operator-(Vec3 const& rhs) const {
    return Vec3{x - rhs.x, y - rhs.y, z - rhs.z};
}

Vec3 Vec3::operator*(Vec3 const& rhs) const {
    return Vec3{x * rhs.x, y * rhs.y, z * rhs.z};
}

Vec3 Vec3::norm() const {
    return *this * (1.f / length());
}

Vec3 Vec3::cross(Vec3 const& other) const {
    return Vec3{
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x,
    };
}

float Vec3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

float Vec3::dot(const Vec3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

float Vec3::distance(Vec3 const& other) const {
    float dx = x - other.x;
    float dy = y - other.y;
    float dz = z - other.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

Vec3 operator+(float rhs, Vec3 const& lhs) {
    return lhs + rhs;
}

Vec3 operator*(float rhs, Vec3 const& lhs) {
    return lhs * rhs;
}
