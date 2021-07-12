#pragma once

struct Vec3 {
    float x = .0f;
    float y = .0f;
    float z = .0f;

    Vec3(float x, float y, float z);
    Vec3() = default;

    Vec3 operator+(float rhs) const;
    Vec3 operator*(float rhs) const;
    Vec3 operator-(float rhs) const;
    Vec3 operator-() const;
    Vec3 operator+(const Vec3& rhs) const;
    Vec3 operator*(const Vec3& rhs) const;
    Vec3 operator-(const Vec3& rhs) const;

    Vec3 norm() const;
    Vec3 cross(const Vec3& other) const;

    float length() const;
    float dot(const Vec3& other) const;
    float distance(const Vec3& other) const;
};

Vec3 operator+(float rhs, const Vec3& lhs);
Vec3 operator*(float rhs, const Vec3& lhs);
Vec3 operator-(float rhs, const Vec3& lhs);
