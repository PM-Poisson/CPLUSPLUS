#pragma once
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "geometrical_object.hpp"

#include <cmath>
#include <ostream>

class circle : public geometrical_object {
    vec2 c;   // centre
    float R;  // rayon

public:
    // Constructeur par défaut
    circle() : c(0.0f, 0.0f), R(1.0f) {}

    // Constructeur avec centre et rayon
    circle(const vec2& center, float radius) : c(center), R(radius) {}

    // Accesseurs
    vec2 center() const { return c; }
    float radius() const { return R; }

    // Évaluation d’un point suivant un paramètre s (0..1)
    vec2 operator()(float s) const override {
        float angle = 2.0f * M_PI * s;
        return c + vec2(R * std::cos(angle), R * std::sin(angle));
    }

    // Point le plus proche d’un point p sur le cercle
    vec2 closest_point(const vec2& p) const override {
        vec2 dir = p - c;
        if (norm(dir) < 1e-6f) // si le point est exactement au centre
            return c + vec2(R, 0.0f);
        return c + normalize(dir) * R;
    }

    // Affichage (optionnel)
    friend std::ostream& operator<<(std::ostream& os, const circle& circ) {
        os << "Circle(center=" << circ.c << ", R=" << circ.R << ")";
        return os;
    }
};

#endif // CIRCLE_HPP
