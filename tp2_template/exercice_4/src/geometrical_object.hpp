#pragma once
#ifndef GEOMETRICAL_OBJECT_HPP 
#define GEOMETRICAL_OBJECT_HPP

#include "vec2.hpp"

class geometrical_object {
public:
    virtual ~geometrical_object() = default;

    // Retourne le point le plus proche d'un point donné
    virtual vec2 closest_point(const vec2& p) const = 0;

    // Évalue la position sur l'objet en fonction d'un paramètre [0,1]
    virtual vec2 operator()(float s) const = 0;
};

#endif