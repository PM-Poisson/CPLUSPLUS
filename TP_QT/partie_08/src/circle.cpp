
#include "circle.hpp"

#include <cmath>

circle::circle()
    :center(),radius(0.0f)
{}

circle::circle(vec2 const& center_param,float const radius_center)
    :center(center_param),radius(radius_center)
{}

bool point_inside_circle(vec2 const& p,circle const& c)
{
    const vec2 u=p-c.center;
    return norm(u)<=c.radius;
}
