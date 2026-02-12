#ifndef BEZIER_HPP
#define BEZIER_HPP
#include <ostream>

template<typename T>
class bezier {
    T P[4];
public:
    T evaluate(double s) const {
        // T doit supporter :
        T result = P[0] * (1-s); // Multiplication par scalaire
        result = result + P[1]; // Addition avec autre T
        return result;
    }
    bezier();
    bezier(T p0, T p1, T p2, T p3);
    T coeff(int i) const;
    T& coeff(int i);
    T operator()(double s) const;
    friend std::ostream& operator<<(std::ostream& os, const bezier& b);
};
// Pour que Bezier<Vec2> fonctionne, Vec2 doit avoir :
class Vec2 {
public:
    Vec2 operator+(const Vec2& other) const; // AdditionVec2 operator*(double scalar) const; // Multiplication scalaire
};

#endif