#pragma once
#ifndef BEZIER_HPP
#define BEZIER_HPP

#include "vec2.hpp"
#include <ostream>
#include <limits>
#include <cmath>
#include <algorithm>

// Classe parente pour le polymorphisme
class geometrical_object {
public:
    virtual ~geometrical_object() = default;

    // Renvoie le point le plus proche d'une position p
    virtual vec2 closest_point(const vec2& p) const = 0;

    // Évalue un point suivant un paramètre s (0..1)
    virtual vec2 operator()(float s) const = 0;
};

template<typename T>
class bezier : public geometrical_object {
    T P[4]; // Points de contrôle

public:
    // Constructeur par défaut
    bezier() : P{} {}

    // Constructeur avec points
    bezier(const T& p0, const T& p1, const T& p2, const T& p3)
        : P{p0, p1, p2, p3} {}

    // Accès const
    const T& coeff(int i) const {
        if(i < 0 || i > 3) throw std::out_of_range("bezier index");
        return P[i];
    }

    // Accès modifiable
    T& coeff(int i) {
        if(i < 0 || i > 3) throw std::out_of_range("bezier index");
        return P[i];
    }

    // Évaluation de la courbe (opérateur)
    T operator()(float s) const override {
        if(s < 0.0f || s > 1.0f) throw std::out_of_range("s out of range");

        float t = 1.0f - s;
        float t2 = t * t, t3 = t2 * t;
        float s2 = s * s, s3 = s2 * s;

        return t3 * P[0]
             + 3.0f * s * t2 * P[1]
             + 3.0f * s2 * t * P[2]
             + s3 * P[3];
    }

    // Approximation discrète pour le point le plus proche
    vec2 closest_point(const vec2& p) const override {
        int N = 100; // nombre d'échantillons
        float min_dist = std::numeric_limits<float>::max();
        vec2 closest;

        for(int i=0; i<=N; ++i) {
            float s = static_cast<float>(i)/N;
            vec2 sample = (*this)(s);
            float d = norm(sample - p);
            if(d < min_dist) {
                min_dist = d;
                closest = sample;
            }
        }
        return closest;
    }

    // Affichage
    friend std::ostream& operator<<(std::ostream& os, const bezier<T>& b) {
        os << "(1-s)^3*" << b.coeff(0)
           << "+3s(1-s)^2*" << b.coeff(1)
           << "+3s^2(1-s)*" << b.coeff(2)
           << "+s^3*" << b.coeff(3);
        return os;
    }
};

#endif // BEZIER_HPP
