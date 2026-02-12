#include "render_area.hpp"
#include "bezier_drawer.hpp"

#include <QPainter>
#include <QMouseEvent>
#include <limits>
#include <iostream>

render_area::render_area(QWidget *parent)
    : QWidget(parent), selected_point(-1), mouse_pos(-1,-1)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    // Création d'une Bézier
    auto b = std::make_shared<bezier<vec2>>(
        vec2(150,100),
        vec2(250,300),
        vec2(450,350),
        vec2(550,180)
    );
    scene.push_back(b);

    // Création d'un cercle
    auto c = std::make_shared<circle>(vec2(400,300), 50.0f);
    scene.push_back(c);

    // Création d'un cercle
    auto c2 = std::make_shared<circle>(vec2(200,750), 90.0f);
    scene.push_back(c2);

    // Création d'un cercle
    auto c3 = std::make_shared<circle>(vec2(680,100), 50.0f);
    scene.push_back(c3);

    closest_point_mouse = vec2(-1,-1);
}

render_area::~render_area() {}

void render_area::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen;
    QBrush brush;
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    // Tracer tous les objets polymorphes
    for(auto const& obj : scene)
    {
        if(auto b = std::dynamic_pointer_cast<bezier<vec2>>(obj))
        {
            pen.setWidth(2); pen.setColor(Qt::blue); painter.setPen(pen);
            draw(painter,*b);

            pen.setWidth(1); pen.setColor(Qt::black); painter.setPen(pen);
            draw_control_polygon(painter,*b);

            pen.setWidth(5);
            for(int k=0;k<4;++k)
            {
                pen.setColor(k==selected_point ? Qt::yellow : Qt::red);
                painter.setPen(pen);
                draw_control_point(painter,*b,k);
            }
        }
        else if(auto c = std::dynamic_pointer_cast<circle>(obj))
        {
            pen.setWidth(2); pen.setColor(Qt::green); painter.setPen(pen);
            const int N = 100;
            for(int i=0;i<N;++i)
            {
                vec2 p0 = (*c)(float(i)/N);
                vec2 p1 = (*c)(float(i+1)/N);
                painter.drawLine(p0.x,p0.y,p1.x,p1.y);
            }
        }
    }

    // Tracer le segment vers le point le plus proche de la souris
    if(closest_point_mouse.x >= 0)
    {
        pen.setWidth(2); pen.setColor(Qt::red);
        painter.setPen(pen);
        painter.drawLine(mouse_pos.x, mouse_pos.y,
                         closest_point_mouse.x, closest_point_mouse.y);
    }
}

void render_area::mouseMoveEvent(QMouseEvent *event)
{
    mouse_pos = vec2(event->x(), event->y());

    // Déplacement du point de contrôle Bézier
    if(selected_point != -1)
    {
        vec2 translation = mouse_pos - click_previous;

        for(auto const& obj : scene)
        {
            if(auto b = std::dynamic_pointer_cast<bezier<vec2>>(obj))
            {
                b->coeff(selected_point) += translation;
                break;
            }
        }
    }

    click_previous = mouse_pos;

    // Calcul du point le plus proche
    float min_dist = std::numeric_limits<float>::max();
    for(auto const& obj : scene)
    {
        vec2 pt = obj->closest_point(mouse_pos);
        float d = norm(pt - mouse_pos);
        if(d < min_dist)
        {
            min_dist = d;
            closest_point_mouse = pt;
        }
    }

    repaint();
}

void render_area::mousePressEvent(QMouseEvent *event)
{
    mouse_pos = vec2(event->x(), event->y());
    selected_point = -1;

    // Vérification pour sélection d'un point Bézier
    for(auto const& obj : scene)
    {
        if(auto b = std::dynamic_pointer_cast<bezier<vec2>>(obj))
        {
            selected_point = select_control_point(*b, mouse_pos);
            if(selected_point != -1) break;
        }
    }

    click_previous = mouse_pos;
    repaint();
}

int render_area::select_control_point(bezier<vec2> const& curve, vec2 const& click)
{
    const float threshold = 25.0f;
    float min_dist = -1.0f;
    int idx = -1;
    for(int k=0;k<4;++k)
    {
        float d = norm(curve.coeff(k) - click);
        if(k==0 || d < min_dist)
        {
            min_dist = d;
            idx = k;
        }
    }
    return min_dist <= threshold ? idx : -1;
}
