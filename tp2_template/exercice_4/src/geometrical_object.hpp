#pragma once
#ifndef GEOMETRICAL_OBJECT_HPP
#define GEOMETRICAL_OBJECT_HPP

#include "vec2.hpp"

/**
 * Classe abstraite représentant un objet géométrique dans le plan 2D.
 * Elle permet de définir une interface commune pour :
 * - L'évaluation d'un point suivant un paramètre s (pour courbes ou cercles)
 * - Le calcul du point le plus proche d'une position donnée
 */
class geometrical_object {
public:
    virtual ~geometrical_object() = default;

    /**
     * Évalue un point de l'objet suivant un paramètre s ∈ [0,1]
     * Pour un cercle : position sur le cercle
     * Pour une courbe Bézier : position sur la courbe
     */
    virtual vec2 operator()(float s) const = 0;

    /**
     * Renvoie le point de l'objet le plus proche d'un point donné p
     */
    virtual vec2 closest_point(const vec2& p) const = 0;
};

#endif // GEOMETRICAL_OBJECT_HPP
