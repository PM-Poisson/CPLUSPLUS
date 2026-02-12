#include <iostream>
#include "bezier.hpp"
#include "export_matlab.hpp"
#include <cstdlib>


/* ===== Vec2 ===== */

struct Vec2 {
    float x, y;

    Vec2() : x(0), y(0) {}
    Vec2(float x_, float y_) : x(x_), y(y_) {}
};

Vec2 operator+(const Vec2& a, const Vec2& b)
{
    return Vec2(a.x + b.x, a.y + b.y);
}

Vec2 operator*(const Vec2& v, float s)
{
    return Vec2(v.x * s, v.y * s);
}

Vec2 operator*(float s, const Vec2& v)
{
    return v * s;
}

std::ostream& operator<<(std::ostream& os, const Vec2& v)
{
    os << v.x << " " << v.y;   // format plus simple pour Matlab
    return os;
}

/* ===== Vec3 ===== */

struct Vec3 {
    double x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(double x_, double y_, double z_)
        : x(x_), y(y_), z(z_) {}
};

Vec3 operator+(const Vec3& a, const Vec3& b)
{
    return Vec3(a.x + b.x,
                a.y + b.y,
                a.z + b.z);
}

Vec3 operator*(const Vec3& v, float s)
{
    return Vec3(v.x * s,
                v.y * s,
                v.z * s);
}

Vec3 operator*(float s, const Vec3& v)
{
    return v * s;
}

std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
    os << v.x << " "
       << v.y << " "
       << v.z;
    return os;
}

/* ===== MAIN ===== */

int main()
{
    std::cout << "=== Tests export Matlab ===\n";

    bezier<float> bf(0.0f, 1.0f, 2.0f, 3.0f);
    export_matlab(bf, "bezier_float.dat");
    if (std::system("python3 ./viewer.py") != 0)
    {    
        std::cerr << "Erreur lancement viewer\n";
    }
    std::cout << "Export float OK\n";

    bezier<double> bd(0.0, 2.0, 4.0, 6.0);
    export_matlab(bd, "bezier_double.dat");
    if (std::system("python3 ./viewer.py") != 0)
    {    
        std::cerr << "Erreur lancement viewer\n";
    }
    std::cout << "Export double OK\n";

    bezier<long double> bld(0.0L, 1.0L, 1.0L, 0.0L);
    export_matlab(bld, "bezier_longdouble.dat");
    if (std::system("python3 ./viewer.py") != 0)
    {    
        std::cerr << "Erreur lancement viewer\n";
    }
    std::cout << "Export long double OK\n";

    bezier<Vec2> b2(
        Vec2(0,0),
        Vec2(1,2),
        Vec2(3,2),
        Vec2(4,0)
    );
    export_matlab(b2, "bezier_vec2.dat");
    if (std::system("python3 ./viewer.py") != 0)
    {    
        std::cerr << "Erreur lancement viewer\n";
    }
    std::cout << "Export Vec2 OK\n";

    bezier<Vec3> b3(
        Vec3(0,0,0),
        Vec3(1,2,3),
        Vec3(4,5,6),
        Vec3(7,8,9)
    );
    export_matlab(b3, "bezier_vec3.dat");
    if (std::system("python3 ./viewer.py") != 0)
    {    
        std::cerr << "Erreur lancement viewer\n";
    }
    std::cout << "Export Vec3 OK\n";

    std::cout << "Tous les exports sont terminés.\n";

    return 0;
}
