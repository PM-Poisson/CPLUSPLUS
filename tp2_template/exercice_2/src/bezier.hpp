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

// Constructeur par défaut
    bezier() : P{} {}

    // Constructeur avec points de contrôle
    bezier(const T& p0, const T& p1,
           const T& p2, const T& p3)
        : P{p0, p1, p2, p3}
    {}

    // Accès const
    const T& coeff(int i) const {
        if(i < 0 || i > 3)
            throw std::exception();
        return P[i];
    }

// Accès modifiable
    T& coeff(int i) {
        if(i < 0 || i > 3)
            throw std::exception();
        return P[i];
    }

    // Évaluation de la courbe
    T operator()(float s) const {
        if(s < 0.0f || s > 1.0f)
            throw std::exception();

        float s2 = s*s;
        float s3 = s2*s;
        float t = 1.0f - s;
        float t2 = t*t;
        float t3 = t2*t;

        return t3 * P[0]
             + 3.0f * s * t2 * P[1]
             + 3.0f * s2 * t * P[2]
             + s3 * P[3];
    }
    
    // Affichage
    friend std::ostream& operator<<(std::ostream& os,
                                    const bezier<T>& b)
    {
        os << "(1-s)^3*" << b.coeff(0)
           << "+3s(1-s)^2*" << b.coeff(1)
           << "+3s^2(1-s)*" << b.coeff(2)
           << "+s^3*" << b.coeff(3);
        return os;
    }
};

// Pour que Bezier<Vec2> fonctionne, Vec2 doit avoir :
class Vec2 {
public:
    Vec2 operator+(const Vec2& other) const; // Addition
    Vec2 operator*(double scalar) const; // Multiplication scalaire
};

#endif