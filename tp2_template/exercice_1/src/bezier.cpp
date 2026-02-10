#include <iostream>
#include "bezier.hpp"
#include <exception>

bezier::bezier()
    : P{}
{}

bezier::bezier(float p0, float p1, float p2, float p3)
    : P{p0, p1, p2, p3}
{}

float bezier::coeff(int i) const
{
    if(i<0 || i>3)
        throw std::exception();
    return P[i];
}

float& bezier::coeff(int i)
{
    if(i<0 || i>3)
        throw std::exception();
    return const_cast<float&>(P[i]);
}

float bezier::operator()(float s) const
{
    if(s<0.0f || s>1.0f)
        throw std::exception();
    return;
}