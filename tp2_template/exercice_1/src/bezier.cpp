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
    return (P[i]);
}

float bezier::operator()(float s) const
{
    if(s<0.0f || s>1.0f)
        throw std::exception();
    
    float const s2 = s*s;
    float const s3 = s2*s;
    float const t = 1.0f-s;
    float const t2 = t*t;
    float const t3 = t2*t;

    return t3*P[0]+3.0f*s*t2*P[1]+3.0f*s2*t*P[2]+s3*P[3];
}

std::ostream& operator<<(std::ostream& os, const bezier& b)
{
    os<<"(1-s)^3*"<<b.coeff(0)
      <<"+3s(1-s)^2*"<<b.coeff(1)
      <<"+3s^2(1-s)*"<<b.coeff(2)
      <<"+s^3*"<<b.coeff(3);
    return os;
}