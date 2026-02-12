#pragma once
#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP

#include <QWidget>
#include <vector>
#include <memory>

#include "vec2.hpp"
#include "bezier.hpp"
#include "circle.hpp"
#include "geometrical_object.hpp"

class render_area : public QWidget
{
    Q_OBJECT
public:
    render_area(QWidget *parent = nullptr);
    ~render_area();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    // Scene polymorphe
    std::vector<std::shared_ptr<geometrical_object>> scene;

    // Point le plus proche de la souris
    vec2 closest_point_mouse;

    // Position de la souris
    vec2 mouse_pos;

    // Sélection de point de contrôle (pour Bézier)
    int selected_point;
    vec2 click_previous;

    // Méthode helper pour sélectionner un point dans une Bézier
    static int select_control_point(bezier<vec2> const& curve, vec2 const& click);
};

#endif
