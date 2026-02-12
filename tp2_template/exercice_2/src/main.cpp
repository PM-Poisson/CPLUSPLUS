#include <iostream>
#include "bezier.hpp"

/*==========================
  Classe Vec2
==========================*/

struct Vec2 {
    float x, y;

    Vec2() : x(0), y(0) {}
    Vec2(float x_, float y_) : x(x_), y(y_) {}
};

// Addition
Vec2 operator+(const Vec2& a, const Vec2& b) {
    return Vec2(a.x + b.x, a.y + b.y);
}

// Multiplication scalaire (Vec2 * float)
Vec2 operator*(const Vec2& v, float s) {
    return Vec2(v.x * s, v.y * s);
}

// Multiplication scalaire (float * Vec2)
Vec2 operator*(float s, const Vec2& v) {
    return v * s;
}

// Affichage
std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

/*==========================
  Classe Vec3
==========================*/

struct Vec3 {
    double x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(double x_, double y_, double z_)
        : x(x_), y(y_), z(z_) {}
};

Vec3 operator+(const Vec3& a, const Vec3& b) {
    return Vec3(a.x + b.x,
                a.y + b.y,
                a.z + b.z);
}

Vec3 operator*(const Vec3& v, float s) {
    return Vec3(v.x * s,
                v.y * s,
                v.z * s);
}

Vec3 operator*(float s, const Vec3& v) {
    return v * s;
}

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << "(" << v.x << ", "
       << v.y << ", "
       << v.z << ")";
    return os;
}

/*==========================
  MAIN
==========================*/

int main()
{
    std::cout << "==== Test float ====\n";
    bezier<float> bf(0.0f, 1.0f, 2.0f, 3.0f);
    std::cout << "Formule: " << bf << "\n";
    std::cout << "b(0.5) = " << bf(0.5f) << "\n\n";


    std::cout << "==== Test double ====\n";
    bezier<double> bd(0.0, 2.0, 4.0, 6.0);
    std::cout << "Formule: " << bd << "\n";
    std::cout << "b(0.3) = " << bd(0.3f) << "\n\n";


    std::cout << "==== Test long double ====\n";
    bezier<long double> bld(0.0L, 1.0L, 1.0L, 0.0L);
    std::cout << "Formule: " << bld << "\n";
    std::cout << "b(0.7) = " << bld(0.7f) << "\n\n";


    std::cout << "==== Test Vec2 (2D) ====\n";
    bezier<Vec2> b2(
        Vec2(0,0),
        Vec2(1,2),
        Vec2(3,2),
        Vec2(4,0)
    );

    std::cout << "Formule: " << b2 << "\n";
    std::cout << "b(0.5) = " << b2(0.5f) << "\n\n";


    std::cout << "==== Test Vec3 (3D) ====\n";
    bezier<Vec3> b3(
        Vec3(0,0,0),
        Vec3(1,2,3),
        Vec3(4,5,6),
        Vec3(7,8,9)
    );

    std::cout << "Formule: " << b3 << "\n";
    std::cout << "b(0.25) = " << b3(0.25f) << "\n";

    return 0;
}
