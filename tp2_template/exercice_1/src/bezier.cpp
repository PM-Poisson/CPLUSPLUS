#include <iostream>
#include "bezier.hpp"

bezier::bezier()
    : P{}
{}

bezier::bezier(float p0, float p1, float p2, float p3)
    : P{p0, p1, p2, p3}
{}

